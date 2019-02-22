/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:51:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/22 11:06:25 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		create_padding(char **s1, char **s2, t_option *opt,
		struct stat *info)
{
	char *tmp;
	char *new;

	tmp = ft_itoa(opt->pad1);
	(*s1)[0] = '%';
	new = ft_strcat(*s1, tmp);
	free(*s1);
	*s1 = ft_strcat(new, "ld ");
	free(new);
	free(tmp);
	tmp = ft_itoa(opt->pad2);
	(*s2)[0] = '%';
	new = ft_strcat(*s2, tmp);
	free(*s2);
	*s2 = ft_strcat(new, "lld ");
	free(new);
	free(tmp);
	get_mode(info, opt, *s1);
	get_time(info, opt, *s2);
}

static void		link_display(t_option *opt, char *av, char *link, char *path)
{
	int		i;
	char	*tmp;

	i = 0;
	if (opt->slash == 1)
	{
		tmp = ft_strcat("/", av);
		i = readlink(tmp, link, BUF_SIZE);
		free(tmp);
	}
	else
	{
		tmp = ft_strcat(path, av);
		i = readlink(tmp, link, BUF_SIZE);
		free(tmp);
	}
	link[i] = '\0';
	ft_printf("%s -> ", av);
	ft_printf("%s\n", link);
}

static void		ft_get_info(char *av, struct stat *info, t_option *opt,
		char *path)
{
	char			*s1;
	char			*s2;
	char			link[BUF_SIZE + 1];

	if (!(s1 = malloc(opt->pad1 + 5)))
		return ;
	if (!(s2 = malloc(opt->pad2 + 6)))
		return ;
	create_padding(&s1, &s2, opt, info);
	if (S_ISLNK(info->st_mode))
		link_display(opt, av, link, path);
	else
		ft_printf("%s\n", av);
	free(s1);
	free(s2);
}

static void		take_the_decision(t_option *opt, char **tmp, char *path)
{
	DIR		*direct;

	if (opt->rep > 0)
	{
		direct = NULL;
		if ((direct = opendir(path)) == NULL)
		{
			if (errno == ENOTDIR)
				opt->error = 2;
			*tmp = ft_strdup(path);
		}
		else
		{
			*tmp = ft_strcat(path, "/");
			closedir(direct);
		}
	}
	else
		*tmp = ft_strcat(path, "/");
}

int				ft_inspect(char *path, char *name, t_option *opt)
{
	struct stat info;
	char		*tmp;
	char		*tmp1;

	opt->dev = 0;
	tmp = NULL;
	take_the_decision(opt, &tmp, path);
	tmp1 = ft_strcat(tmp, name);
	if (lstat(tmp1, &info) == -1)
		return (-1);
	ft_get_info(name, &info, opt, tmp);
	free(tmp);
	free(tmp1);
	return (0);
}
