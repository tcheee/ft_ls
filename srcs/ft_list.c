/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:16:44 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/01 19:49:27 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int			i;
	DIR			*direct;
	struct		dirent *info;
	t_option	opt;

	direct = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	else
	{
		get_option(ac, av, &opt);
		while (i <= ac - 1)
		{
			//if ((direct = opendir(av[i])) == NULL)
			//	manage_error();
			while ((info = readdir(direct)) != NULL)
			{
				if (opt.a == 0)
					if ((info->d_name)[0] == '.')
						ft_printf("%s\n", info->d_name);
				 if (opt.a == 1)
					ft_printf("%s\n", info->d_name);
			}
		}
		closedir(direct);
		i++;
	}
	return (0);
}
