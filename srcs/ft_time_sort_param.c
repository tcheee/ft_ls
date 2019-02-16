/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:38:23 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/15 14:34:50 by tcherret         ###   ########.fr       */
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

char		**ft_time_sort_param(char **list, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < nb)
	{
		i = 0;
		while (i < nb)
		{
			if (ft_cmptime_param(list[i], list[i + 1]) != 0)
			{
				if (list[i + 1] && ft_cmptime_param(list[i], list[i + 1]) < 0)
				{
					tmp = ft_strdup(list[i]);
					list[i] = ft_strdup(list[i + 1]);
					list[i + 1] = ft_strdup(tmp);
					free(tmp);
				}
			}
			else
			{
				if (list[i + 1] && ft_strcmp(list[i], list[i + 1]) > 0)
				{
					tmp = ft_strdup(list[i]);
					list[i] = ft_strdup(list[i + 1]);
					list[i + 1] = ft_strdup(tmp);
					free(tmp);
				}
			}
			i++;
		}
		j++;
	}
	return (list);
}

char		**ft_rtime_sort_param(char **list, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < nb)
	{
		i = 0;
		while (i < nb)
		{
			if (ft_cmptime_param(list[i], list[i + 1]) != 0)
			{
				if (list[i + 1] && ft_cmptime_param(list[i], list[i + 1]) > 0)
				{
					tmp = ft_strdup(list[i]);
					list[i] = ft_strdup(list[i + 1]);
					list[i + 1] = ft_strdup(tmp);
					free(tmp);
				}
			}
			else
			{
				if (list[i + 1] && ft_strcmp(list[i], list[i + 1]) < 0)
				{
					tmp = ft_strdup(list[i]);
					list[i] = ft_strdup(list[i + 1]);
					list[i + 1] = ft_strdup(tmp);
					free(tmp);
				}
			}
			i++;
		}
		j++;
	}
	return (list);
}
