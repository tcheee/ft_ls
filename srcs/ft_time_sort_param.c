/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:38:23 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/22 20:33:37 by tcherret         ###   ########.fr       */
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

static int	ft_cmptype(char *lista, char *listb)
{
	struct stat	info;
	struct stat	info2;

	if (lstat(lista, &info) == -1)
		return (-1);
	if (lstat(listb, &info2) == -1)
		return (-1);
	if (S_ISDIR(info.st_mode) && S_ISDIR(info2.st_mode))
		return (0);
	else if (S_ISDIR(info.st_mode))
		return (1);
	else if (S_ISDIR(info2.st_mode))
		return (-1);
	else
		return (0);
}

static void	do_the_swap(char **list, int i)
{
	char *tmp;

	if (ft_cmptime_param(list[i], list[i + 1]) != 0)
	{
		if (list[i + 1] && ft_cmptime_param(list[i], list[i + 1]) < 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
		}
	}
	else
	{
		if (list[i + 1] && ft_cmptype(list[i], list[i + 1]) < 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
		}
	}
}

char		**ft_time_sort_param(char **list, int nb)
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
