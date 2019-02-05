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

/*static void		slash_16(char **name)
{
	int len;

	len = ft_strlen(*name);
	if ((*name)[len - 1] == '/')
		(*name)[len - 1] = '\0';
}*/

int		main(int ac, char **av)
{
	int				i;
	t_option		opt;

	i = 1;
	check_error_ls(ac, av, &opt);
	get_option(ac, av, &opt, &i);
	if (i == ac)
	{
		ft_ls_recur(ft_strdup("."), &opt);
	}
	else
	{
		while (i < ac)
		{
			//slash_16(&av[i]);
			ft_ls_recur(av[i], &opt);
			i++;
		}
	}
	//while (1);
	return (0);
}
