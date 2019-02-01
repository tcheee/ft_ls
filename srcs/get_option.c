/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:12:22 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/01 19:48:46 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	init_opt(t_option *opt)
{
	(*opt).l = 0;
	(*opt).a = 0;
	(*opt).Re = 0;
	(*opt).t = 0;
	(*opt).r = 0;
}

void		get_option(int ac, char **av, t_option *opt)
{
	int i;
	int j;

	i = 1;
	init_opt(opt);
	while (i < ac)
	{
		if ((unsigned char)av[i][0] == (unsigned char)('-'))
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				if (av[i][j] == 'l')
					(*opt).l = 1;
				else if (av[i][j] == 'a')
					(*opt).a = 1;
				else if (av[i][j] == 'R')
					(*opt).Re = 1;
				else if (av[i][j] == 't')
					(*opt).t = 1;
				else if (av[i][j] == 'r')
					(*opt).r = 1;
				j++;
			}
		}
		else
			break ;
		i++;
	}
}
