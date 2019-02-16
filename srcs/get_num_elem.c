/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:40:56 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/16 13:20:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		get_num_elem(DIR *direct, char *name, t_option *opt)
{
	int i;
	struct dirent *info;

	i = 0;
	direct = opendir(name);
	while ((info = readdir(direct)) != NULL)
	{
		ft_printf("info_name = %s\n", info->d_name);
		i++;
	}
	ft_printf("go out\n");
	closedir(direct);
	opt->elem = i;
	return (i);
}

int		get_num_arg(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
			j++;
		i++;
	}
	return (j);
}
