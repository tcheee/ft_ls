/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_get_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:40:20 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 16:46:12 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_size_major(struct stat *info, t_option *opt, char *s2)
{
	struct group	*grp;

	grp = getgrgid(info->st_gid);
	if (opt->dev == 0)
	{
		ft_printf("%s ", (grp)->gr_name);
		ft_printf(s2, info->st_size);
	}
	else if (opt->dev == 1)
	{
		ft_printf("%-15s ", (grp)->gr_name);
		if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
		{
			ft_printf("%d, ", major(info->st_rdev));
			ft_printf("%d ", minor(info->st_rdev));
		}
		else
			ft_printf(s2, info->st_size);
	}
}

void		get_time(struct stat *info, t_option *opt, char *s2)
{
	char			time[13];
	int				i;
	int				j;

	print_size_major(info, opt, s2);
	i = 0;
	j = 4;
	while (i < 12)
	{
		time[i] = ctime(&(info->st_ctime))[j];
		i++;
		j++;
	}
	time[12] = '\0';
	ft_printf("%s ", time);
}
