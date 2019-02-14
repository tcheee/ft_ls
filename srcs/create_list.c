/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:43:24 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/14 11:43:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		create_list(int *i, struct dirent *info, DIR *direct, char **list)
{
	*i = 0;
	while ((info = readdir(direct)) != NULL)
	{
		if ((list[*i] = ft_strdup(info->d_name)) == NULL)
			return ;
		(*i)++;
	}
	closedir(direct);
}
