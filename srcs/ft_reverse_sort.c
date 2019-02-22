/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:42:32 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/21 22:47:19 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**ft_reverse_sort(char **list, int nb)
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
			if (list[i + 1] && ft_strcmp(list[i], list[i + 1]) < 0)
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
