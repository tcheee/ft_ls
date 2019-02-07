/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:52:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/07 17:41:50 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		find_number(t_option *opt, struct stat *info)
{
	int sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	ft_nblen(info->st_nlink, 10, &sum1);
	ft_nblen(info->st_size, 10, &sum2);
	opt->tot += info->st_blocks;
	if (sum1 > opt->pad1)
		opt->pad1 = sum1;
	if (sum2 > opt->pad2)
		opt->pad2 = sum2;
}

int		get_padding(char *path, t_option *opt, char **list, int j)
{
	int				i;
	char			*stock;
	struct stat		info;

	i = 0;
	while (i < j)
	{
		stock = ft_strdup(path);
		if ((opt->a && list[i][0] == '.') || list[i][0] != '.')
		{
			path = ft_strcat(path, "/");
			if ((lstat(ft_strcat(path, list[i]), &info) == -1))
				return (-1);
			find_number(opt, &info);
		}
		path = ft_strdup(stock);
		//free(stock);
		i++;
	}
	return (0);
}
