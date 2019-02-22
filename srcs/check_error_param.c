/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:06:03 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 22:44:48 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		check_dash_param(int ac, char **av, t_option *opt, int *i)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[*i], "-") == 0)
		{
			managerror(av[*i]);
			(*i)++;
			exit(0);
		}
	}
	else
	{
		if (ft_strcmp(av[*i], "-") == 0)
		{
			opt->error = 1;
			managerror(av[*i]);
			(*i)++;
		}
	}
}

static int		check_file_param(char **av, t_option *opt, int total)
{
	DIR		*direct;
	int		i;

	i = 0;
	direct = NULL;
	while (i < total)
	{
		if (av[i])
		{
			if ((direct = opendir(av[i])) == NULL)
				managerror_file(av[i], opt);
			else
				closedir(direct);
			i++;
		}
	}
	return (0);
}

int				check_error_ls_param(int ac,
		char **av, t_option *opt, int total)
{
	DIR		*direct;
	int		i;

	i = 0;
	opt->error = 0;
	direct = NULL;
	if (av[i])
		check_dash_param(ac, av, opt, &i);
	while (i < total)
	{
		if (av[i])
		{
			if ((direct = opendir(av[i])) == NULL)
			{
				opt->error = 1;
				managerror(av[i]);
			}
			else
				closedir(direct);
			i++;
		}
	}
	check_file_param(av, opt, total);
	return (0);
}
