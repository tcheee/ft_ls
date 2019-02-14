/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:38:23 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/14 11:39:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_cmptime(char *path, char *lista, char *listb)
{
	struct stat info;
	struct stat	info2;

	path = ft_strcat(path, "/");
	if (lstat(ft_strcat(path, lista), &info) == -1)
		return (-1);
	if (lstat(ft_strcat(path, listb), &info2) == -1)
		return (-1);
	return (info.st_ctime - (info2.st_ctime));
}

char		**ft_time_sort(char *name, char **list, t_option *opt)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < opt->elem - 1)
	{
		i = 0;
		while (i < opt->elem - 1)
		{
			if (list[i + 1] && ft_cmptime(name, list[i], list[i + 1]) < 0)
			{
				tmp = ft_strdup(list[i]);
				list[i] = ft_strdup(list[i + 1]);
				list[i + 1] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
	return (list);
}

char		**ft_rtime_sort(char *name, char **list, t_option *opt)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < opt->elem - 1)
	{
		i = 0;
		while (i < opt->elem - 1)
		{
			if (list[i + 1] && ft_cmptime(name, list[i], list[i + 1]) > 0)
			{
				tmp = ft_strdup(list[i]);
				list[i] = ft_strdup(list[i + 1]);
				list[i + 1] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
	return (list);
}
