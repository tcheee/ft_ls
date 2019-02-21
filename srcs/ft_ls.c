/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:35:17 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 16:31:52 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	create_param(int ac, char **av, char **param, int i)
{
	int j;

	j = 0;
	while (av[i] && i < ac)
	{
		param[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	return (j);
}

static void	sort_param(char **param, int total, t_option *opt)
{
	if (opt->t == 1 && opt->r == 1)
		param = ft_rtime_sort_param(param, total - 1);
	else if (opt->t == 1)
		param = ft_time_sort_param(param, total - 1);
	else if (opt->r == 1)
		param = ft_reverse_sort(param, total - 1);
	else
		param = ft_sort(param, total - 1);
}

static void	do_the_work(char **param, t_option *opt, int *i)
{
	if (ft_strcmp("/", param[*i]) == 0)
		opt->slash = 1;
	if ((opt->rep > 1 && opt->aff == 0 && opt->error == 0))
		ft_printf("%s:\n", param[*i]);
	ft_ls_recur(param[*i], opt);
	if (opt->rep > 1 && opt->aff != 3)
		opt->aff = 1;
	(*i)++;
}

int			main(int ac, char **av)
{
	int				i;
	t_option		opt;
	char			**param;
	int				total;

	i = 1;
	get_option(ac, av, &opt, &i);
	if (i == ac)
	{
		check_error_ls(ac, av, &opt);
		ft_ls_recur(ft_strdup("."), &opt);
	}
	else
	{
		if (!(param = malloc(sizeof(char**) * (ac - i))))
			return (-1);
		total = create_param(ac, av, param, i);
		sort_param(param, total, &opt);
		check_error_ls_param(ac, param, &opt, total);
		i = 0;
		while (i < total)
			do_the_work(param, &opt, &i);
	}
	//while (1);
	return (0);
}
