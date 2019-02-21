/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:51:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 16:45:51 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		create_padding(char **s1, char **s2, t_option *opt,
		struct stat *info)
{
	char *tmp;

	tmp = ft_itoa(opt->pad1);
	(*s1)[0] = '%';
	*s1 = ft_strcat(*s1, tmp);
	*s1 = ft_strcat(*s1, "ld ");
	free(tmp);
	tmp = ft_itoa(opt->pad2);
	(*s2)[0] = '%';
	*s2 = ft_strcat(*s2, tmp);
	*s2 = ft_strcat(*s2, "lld ");
	free(tmp);
	get_mode(info, opt, *s1);
	get_time(info, opt, *s2);
}

static void		ft_get_info(char *av, struct stat *info, t_option *opt,
		char *path)
{
	char			*s1;
	char			*s2;
	char			link[BUF_SIZE + 1];
	int				i;

	i = 0;
	if (!(s1 = malloc(opt->pad1 + 5)))
		return ;
	if (!(s2 = malloc(opt->pad2 + 6)))
		return ;
	create_padding(&s1, &s2, opt, info);
	if (S_ISLNK(info->st_mode))
	{
		if (opt->slash == 1)
			i = readlink(ft_strcat("/", av), link, BUF_SIZE);
		else
			i = readlink(ft_strcat(path, av), link, BUF_SIZE);
		link[i] = '\0';
		ft_printf("%s -> ", av);
		ft_printf("%s\n", link);
	}
	else
		ft_printf("%s\n", av);
	free(s1);
	free(s2);
}

int				ft_inspect(char *path, char *name, t_option *opt)
{
	struct stat info;
	DIR			*direct;

	opt->dev = 0;
	if (opt->rep > 0)
	{
		direct = NULL;
		if ((direct = opendir(path)) == NULL)
		{
			if (errno == ENOTDIR)
				opt->error = 2;
		}
		else
		{
			path = ft_strcat(path, "/");
			closedir(direct);
		}
	}
	else
		path = ft_strcat(path, "/");
	if (lstat(ft_strcat(path, name), &info) == -1)
		return (-1);
	ft_get_info(name, &info, opt, path);
	return (0);
}
