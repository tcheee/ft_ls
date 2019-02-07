/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:35:33 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/07 17:46:06 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		managerror(char *name, t_option *opt)
{
	DIR		*direct;

	direct = NULL;
	if ((direct = opendir(name)) == NULL)
	{
		if (errno == ENOTDIR)
		{
			opt->error = 2;
			if (opt->l == 0)
				ft_printf("%s\n", name);
			else if (opt->l == 1)
				ft_inspect("", name, opt);
			return (0);
		}
		else
			ft_printf("%s: %s: %s \n", "ft_ls", name, strerror(errno));;
	}
	return (-1);
}

int		managerror_bis(char *name)
{
	DIR		*direct;

	direct = NULL;
	if ((direct = opendir(name)) == NULL)
		return (-1);
	return (-1);
}
