/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtime_sort_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:58:37 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 23:38:44 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_cmptime_param(char *lista, char *listb)
{
	struct stat	info;
	struct stat	info2;

	if (lstat(lista, &info) == -1)
		return (-1);
	if (lstat(listb, &info2) == -1)
		return (-1);
	return (info.st_ctime - (info2.st_ctime));
}

static void	do_the_swap(char **list, int i)
{
	char	*tmp;

	if (ft_cmptime_param(list[i], list[i + 1]) != 0)
	{
		if (list[i + 1] && ft_cmptime_param(list[i], list[i + 1]) > 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			free(tmp);
		}
	}
	else
	{
		if (list[i + 1] && ft_strcmp(list[i], list[i + 1]) < 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			free(tmp);
		}
	}
}

char		**ft_rtime_sort_param(char **list, int nb)
{
	int		i;
	int		j;

	j = 0;
	while (j < nb)
	{
		i = 0;
		while (i < nb)
		{
			do_the_swap(list, i);
			i++;
		}
		j++;
	}
	return (list);
}
