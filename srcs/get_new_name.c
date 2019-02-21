/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:24:11 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 17:41:24 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*is_it_slash(char *name, t_option *opt)
{
	if (opt->slash == 0)
		name = ft_strcat(name, "/");
	return (name);
}

static void	do_the_work(char *name, char **list, t_option *opt, int i)
{
	int			total;
	char		*old_name;
	struct stat	info;

	total = opt->elem;
	old_name = ft_strdup(name);
	if (opt->slash == 0)
		name = ft_strcat(name, "/");
	if (lstat(ft_strcat(name, list[i]), &info) == -1)
		return ;
	name = old_name;
	if (S_ISDIR(info.st_mode))
	{
		if (ft_strcmp(list[i], ".") && ft_strcmp(list[i], ".."))
			if ((opt->a == 1 && (list[i][0] == '.')) || (list[i][0] != '.'))
			{
				old_name = ft_strdup(name);
				name = is_it_slash(name, opt);
				name = ft_strcat(name, list[i]);
				ft_printf("\n%s:\n", name);
				ft_ls_recur(name, opt);
				name = old_name;
				opt->elem = total;
			}
	}
}

char		*get_new_name(char *name, char **list, t_option *opt)
{
	DIR				*direct;
	int				i;

	opt->in = 1;
	direct = NULL;
	if ((direct = opendir(name)) == NULL)
		managerror_bis(name);
	else
	{
		i = 0;
		while (i < opt->elem && list[i])
		{
			do_the_work(name, list, opt, i);
			i++;
		}
	}
	closedir(direct);
	return (NULL);
}
