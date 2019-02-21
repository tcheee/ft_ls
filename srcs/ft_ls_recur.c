/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:34:31 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 17:42:20 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		do_the_check(char *name, t_option *opt)
{
	if (opt->in == 0)
		managerror_bis1(name);
	else if (opt->in == 1)
		managerror_bis(name);
}

static void		print_option(char *name, t_option *opt, DIR *direct, int *i)
{
	opt->slash = 0;
	if (ft_strcmp(name, "/") == 0)
		opt->slash = 1;
	if (opt->error == 1 && opt->aff != 3)
	{
		ft_printf("%s:\n", name);
		opt->aff = 3;
	}
	else if (opt->error == 2 || opt->aff == 3 || opt->aff == 1)
		ft_printf("\n%s:\n", name);
	*i = get_num_elem(direct, name, opt);
}

static void		finish_algo(char **name, char **list, int j, t_option *opt)
{
	if (opt->l >= 1)
		get_padding(*name, opt, list, j);
	display_list(list, j, opt, *name);
	if (opt->re == 1)
		*name = get_new_name(*name, list, opt);
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
		do_the_check(name, opt);
	else
	{
		print_option(name, opt, direct, &i);
		if (!(list = malloc(sizeof(char**) * i)))
			return (-1);
		j = i;
		create_list(&i, info, direct, list);
		finish_algo(&name, list, j, opt);
		free(list);
	}
	//closedir(direct);
	return (0);
}
