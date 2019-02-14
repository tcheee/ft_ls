/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:35:17 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/13 18:08:48 by tcherret         ###   ########.fr       */
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
	get_option(ac, av, &opt, &i);
	check_error_ls(ac, av, &opt);
	if (i == ac)
	{
		ft_ls_recur(ft_strdup("."), &opt);
	}
	else
	{
		while (i < ac)
		{
			if ((opt.rep > 1 && opt.aff == 0 && opt.error == 0))
				ft_printf("%s:\n", av[i]);
			ft_ls_recur(av[i], &opt);
			if (opt.rep > 1)
				opt.aff = 1;
			i++;
		}
	}
	//while (1);
	return (0);
}
