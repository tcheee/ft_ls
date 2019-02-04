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
	int				i;
	t_option		opt;

	i = 1;
	get_option(ac, av, &opt, &i);
	//check_error(ac, av);
	if (i == ac)
		ft_list(ac, av, &opt, &i);
	else
		ft_list_test_recur(ac, av, &opt, &i);
	return (0);
}
