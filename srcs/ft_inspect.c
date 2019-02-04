/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:51:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/31 17:52:15 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		get_mode(struct stat *info)
{
	ft_printf( (S_ISDIR(info->st_mode)) ? "d" : "-");
	ft_printf( (info->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (info->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf( (info->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf( (info->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (info->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf( (info->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf( (info->st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (info->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf( (info->st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

static void		ft_get_info(char *av, struct stat *info)
{
	struct passwd	*id;
	struct group	*grp;

	id = getpwuid(info->st_uid);
	grp = getgrgid(info->st_gid);
	ft_printf("%s ", av);
	get_mode(info);
	ft_printf("%ld ", info->st_nlink);
	ft_printf("%s ", id->pw_name);
	ft_printf("%s ", grp->gr_name);
	ft_printf("%lld ", info->st_size);
	ft_printf("%s", ctime(&(info->st_mtime))); // to modify to be the same
}

int				ft_inspect(char *av)
{
	struct stat info;

	if (stat(av, &info) == -1)
		return (-1);
	ft_get_info(av, &info);
	return (0);
}
