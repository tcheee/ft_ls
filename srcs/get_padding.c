/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:52:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 23:17:21 by tcherret         ###   ########.fr       */
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

int				get_padding(char *path, t_option *opt, char **list, int j)
{
	int				i;
	char			*stock;
	struct stat		info;
	char			*tmp;

	i = 0;
	opt->tot = 0;
	while (i < j)
	{
		stock = path;
		if ((opt->a && list[i][0] == '.') || list[i][0] != '.')
		{
			tmp = ft_strcat(path, "/");
			path = ft_strcat(tmp, list[i]);
			free(tmp);
			if ((lstat(path, &info) == -1))
				return (-1);
			find_number(opt, &info);
			free(path);
		}
		path = stock;
		i++;
	}
	return (0);
}
