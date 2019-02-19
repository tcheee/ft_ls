/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:51:50 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/18 14:07:09 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		get_mode(struct passwd **id, t_option *opt,
		struct stat *info, char *s1)
{
	*id = getpwuid(info->st_uid);
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
		ft_printf("%-9s ", (*id)->pw_name);
	else
		ft_printf("%s ", (*id)->pw_name);
}

static void		get_time(struct stat *info, t_option *opt, struct group **grp,
		char *s2)
{
	char			time[13];
	int				i;
	int				j;

	*grp = getgrgid(info->st_gid);
	if (opt->dev == 0)
	{
		ft_printf("%s ", (*grp)->gr_name);
		ft_printf(s2, info->st_size);
	}
	else if (opt->dev == 1)
	{
		ft_printf("%-15s ", (*grp)->gr_name);
		if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
		{
			ft_printf("%d, ", major(info->st_rdev));
			ft_printf("%d ", minor(info->st_rdev));
		}
		else
			ft_printf(s2, info->st_size);
	}
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

static void		create_padding(char **s1, char **s2, t_option *opt)
{
	char *tmp;

	tmp = ft_itoa(opt->pad1);
	(*s1)[0] = '%';
	*s1 = ft_strcat(*s1, tmp);
	*s1 = ft_strcat(*s1, "ld ");
	free(tmp);
	tmp = ft_itoa(opt->pad2);
	(*s2)[0] = '%';
	*s2 = ft_strcat(*s2, tmp);
	*s2 = ft_strcat(*s2, "lld ");
	free(tmp);
}

static void		ft_get_info(char *av, struct stat *info, t_option *opt)
{
	struct passwd	*id;
	struct group	*grp;
	char			*s1;
	char			*s2;
	//char			*link;

	if (!(s1 = malloc(opt->pad1 + 5)))
		return ;
	if (!(s2 = malloc(opt->pad2 + 6)))
		return ;
	create_padding(&s1, &s2, opt);
	get_mode(&id, opt, info, s1);
	get_time(info, opt, &grp, s2);
	/*if (S_ISLNK(info->st_mode))
	  {
	  if (!(link = malloc(sizeof(char*) * 10000)))
	  return ;
	  readlink(av, link, 10000);
	  ft_printf("%s -> %s\n", av, link);
	  free(link);
	  }*/
	//else
	ft_printf("%s\n", av);
	free(s1);
	free(s2);
}

int				ft_inspect(char *path, char *name, t_option *opt)
{
	struct stat info;
	DIR			*direct;

	opt->dev = 0;
	if (opt->rep > 0)
	{
		direct = NULL;
		if ((direct = opendir(path)) == NULL)
		{
			if (errno == ENOTDIR)
				opt->error = 2;
		}
		else
		{
			path = ft_strcat(path, "/");
			closedir(direct);
		}
	}
	else
		path = ft_strcat(path, "/");
	if (lstat(ft_strcat(path, name), &info) == -1)
		return (-1);
	ft_get_info(name, &info, opt);
	return (0);
}
