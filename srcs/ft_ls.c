/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:35:17 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/07 17:51:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>

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
			if (ac > 3 && opt.l == 1)
				ft_printf("%s:\n", av[i]);
			ft_ls_recur(av[i], &opt);
			if (ac > 3 && opt.l == 1)
				opt.l = 2;
			i++;
		}
	}
	//while (1);
	return (0);
}
