/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:39:52 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/19 20:40:02 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		display_list(char **list, int j, t_option *opt, char *name)
{
	int		i;
	char	*stock;

	i = -1;
	while (++i < j - 1)
		if (list[i] == NULL)
			return ;
	stock = ft_strdup(name);
	if (opt->t == 1 && opt->r == 1)
		ft_rtime_sort(stock, list, opt);
	else if (opt->t == 1)
		list = ft_time_sort(stock, list, opt);
	else if (opt->r == 1)
		list = ft_reverse_sort(list, opt->elem - 1);
	else
		list = ft_sort(list, opt->elem - 1);
	i = 0;
	if (opt->l >= 1)
		ft_printf("total %d\n", opt->tot);
	while (i < j - 1)
	{
		if ((opt->a && list[i][0] == '.') || list[i][0] != '.')
			opt->l == 0 ?
				ft_printf("%s\n", list[i]) : ft_inspect(stock, list[i], opt);
		i++;
	}
	free(stock);
}
