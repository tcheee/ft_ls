/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtime_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:00:06 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 23:41:17 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_cmptime(char *path, char *lista, char *listb)
{
	struct stat info;
	struct stat	info2;
	char		*tmp;
	char		*tmp1;

	tmp = ft_strcat(path, "/");
	tmp1 = ft_strcat(tmp, lista);
	if (lstat(tmp1, &info) == -1)
		return (-1);
	free(tmp1);
	tmp1 = ft_strcat(tmp, listb);
	if (lstat(tmp1, &info2) == -1)
		return (-1);
	free(tmp1);
	free(tmp);
	return (info.st_ctime - (info2.st_ctime));
}

static void	do_the_swap(char *name, char **list, int i)
{
	char *tmp;

	if (ft_cmptime(name, list[i], list[i + 1]) != 0)
	{
		if (list[i + 1] && ft_cmptime(name, list[i], list[i + 1]) > 0)
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

char		**ft_rtime_sort(char *name, char **list, t_option *opt)
{
	int		i;
	int		j;

	j = 0;
	while (j < opt->elem - 1)
	{
		i = 0;
		while (i < opt->elem - 1)
		{
			do_the_swap(name, list, i);
			i++;
		}
		j++;
	}
	return (list);
}
