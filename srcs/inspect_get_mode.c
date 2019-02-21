/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_get_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:38:09 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 16:40:09 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	get_first_mode(struct stat *info, t_option *opt)
{
	if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
		opt->dev = 1;
	if (S_ISDIR(info->st_mode))
		ft_printf("d");
	else if (S_ISCHR(info->st_mode))
		ft_printf("c");
	else if (S_ISBLK(info->st_mode))
		ft_printf("b");
	else if (S_ISLNK(info->st_mode))
		ft_printf("l");
	else
		ft_printf("-");
}

void		get_mode(struct stat *info, t_option *opt, char *s1)
{
	struct passwd *id;

	id = getpwuid(info->st_uid);
	get_first_mode(info, opt);
	ft_printf((info->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((info->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((info->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((info->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((info->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((info->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((info->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((info->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((info->st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
	ft_printf(s1, info->st_nlink);
	if (opt->dev == 1)
		ft_printf("%-9s ", (id)->pw_name);
	else
		ft_printf("%s ", (id)->pw_name);
}
