/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:12:22 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/07 17:38:54 by tcherret         ###   ########.fr       */
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
	(*opt).tot = 0;
	(*opt).pad1 = 0;
	(*opt).pad2 = 0;
	(*opt).nb = 0;
	(*opt).elem = 0;
	(*opt).dev = 0;
}

static void	incrementer(char **av, t_option *opt, int *i, int *j)
{
	if (av[*i][*j] == 'l')
		(*opt).l = 1;
	else if (av[*i][*j] == 'a')
		(*opt).a = 1;
	else if (av[*i][*j] == 'R')
		(*opt).Re = 1;
	else if (av[*i][*j] == 't')
		(*opt).t = 1;
	else if (av[*i][*j] == 'r')
		(*opt).r = 1;
	else
	{
		ft_printf("ft_ls: illegal option -- %c\n", av[*i][*j]);
		ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
		exit(0);
	}
	(*j)++;

}

void		get_option(int ac, char **av, t_option *opt, int *i)
{
	int j;

	init_opt(opt);
	while (*i < ac)
	{
		if ((unsigned char)av[*i][0] == (unsigned char)('-'))
		{
			j = 1;
			while (av[*i][j] != '\0')
				incrementer(av, opt, i, &j);
		}
		else
			break ;
		(*i)++;
	}
	if (ac > 3)
		(*opt).nb = 1;
}
