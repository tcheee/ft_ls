/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:34:41 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/18 14:05:58 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		check_option(char *str)
{
	int j;

	j = 0;
	if (str[j] == '-')
	{
		j++;
		while (str[j] != '\0')
		{
			if (str[j] != 'R' && str[j] != 'a' && str[j] != 'l'
					&& str[j] != 'r' && str[j] != 't')
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}

static void		check_dash(int ac, char **av, t_option *opt, int *i)
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

static int		check_file(int ac, char **av, t_option *opt)
{
	DIR		*direct;
	int		i;

	i = 1;
	direct = NULL;
	if (av[i])
		check_dash(ac, av, opt, &i);
	while (av[i] && check_option(av[i]) == 1)
		i++;
	while (i < ac)
	{
		if (av[i])
		{
			if ((direct = opendir(av[i])) == NULL)
				managerror_file(av[i], opt);
			i++;
		}
	}
	return (0);
}

int				check_error_ls(int ac, char **av, t_option *opt)
{
	DIR		*direct;
	int		i;

	i = 1;
	opt->error = 0;
	direct = NULL;
	if (av[i])
		check_dash(ac, av, opt, &i);
	while (av[i] && check_option(av[i]) == 1)
		i++;
	while (i < ac)
	{
		if (av[i])
		{
			if ((direct = opendir(av[i])) == NULL)
			{
				opt->error = 1;
				managerror(av[i]);
			}
			i++;
		}
	}
	check_file(ac, av, opt);
	return (0);
}
