/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:35:25 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 22:26:28 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_sort(char **list, int nb)
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
			if (list[i + 1] && list[i] && ft_strcmp(list[i], list[i + 1]) > 0)
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
	return (list);
}
