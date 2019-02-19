/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:34:31 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/18 18:31:33 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*get_new_name(char *name, char **list, t_option *opt)
{
	DIR				*direct;
	char			*old_name;
	int				i;
	int				total;
	struct stat		info;

	old_name = NULL;
	direct = NULL;
	if ((direct = opendir(name)) == NULL)
		managerror_bis(name);
	else
	{
		i = 0;
		while (i < opt->elem && list[i])
		{
			total = opt->elem;
			old_name = ft_strdup(name);
			if (opt->slash == 0)
				name = ft_strcat(name, "/");
			if (lstat(ft_strcat(name, list[i]), &info) == -1)
				return (NULL);
			name = old_name;
			if (S_ISDIR(info.st_mode))
			{
				if (ft_strcmp(list[i], ".")
						&& ft_strcmp(list[i], ".."))
					if ((opt->a == 1 && (list[i][0] == '.'))
							|| (list[i][0] != '.'))
					{
						old_name = ft_strdup(name);
						if (opt->slash == 0)
							name = ft_strcat(name, "/");
						name = ft_strcat(name, list[i]);
						ft_printf("\n%s:\n", name);
						ft_ls_recur(name, opt);
						name = old_name;
						opt->elem = total;
					}
			}
			i++;
		}
	}
	closedir(direct);
	return (NULL);
}

int				ft_ls_recur(char *name, t_option *opt)
{
	DIR				*direct;
	struct dirent	*info;
	char			**list;
	int				i;
	int				j;

	direct = NULL;
	info = NULL;
	j = 0;
	if (name == NULL)
		return (0);
	if ((direct = opendir(name)) == NULL)
		managerror_bis(name);
	else
	{
		if (ft_strcmp(name, "/") == 0)
			opt->slash = 1;
		if (opt->error == 1 && opt->aff == 0)
			ft_printf("%s:\n", name);
		else if (opt->error == 2 || opt->aff == 1)
			ft_printf("\n%s:\n", name);
		i = get_num_elem(direct, name, opt);
		if (!(list = malloc(sizeof(char**) * i)))
			return (-1);
		j = i;
		create_list(&i, info, direct, list);
		if (opt->l >= 1)
			get_padding(name, opt, list, j);
		display_list(list, j, opt, name);
		if (opt->re == 1)
			name = get_new_name(name, list, opt);
		free(list);
	}
	return (0);
}
