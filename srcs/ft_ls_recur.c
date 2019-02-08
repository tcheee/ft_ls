/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:34:31 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/08 18:14:37 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		get_num_elem(DIR *direct, char *name)
{
	int i;

	i = 0;
	direct = opendir(name);
	while (readdir(direct) != NULL)
		i++;
	closedir(direct);
	return (i);
}

static void		display_list(char **list, int j, t_option *opt, char *name)
{
	int i;
	char	*stock;

	//list = ft_sort(list, opt);
	i = 0;
	if (opt->l >= 1)
		ft_printf("total %d\n", opt->tot);
	while (i < j)
	{
		stock = ft_strdup(name);
		if ((opt->a && list[i][0] == '.') || list[i][0] != '.')
			opt->l == 0 ? ft_printf("%s\n", list[i]) : ft_inspect(stock, list[i], opt);
		free(stock);
		free(list[i]);
		i++;
	}
	//penser a free ici;
}

static char		*get_new_name(char *name, t_option *opt)
{
	DIR				*direct;
	struct	dirent	*info;
	char			*old_name;

	old_name = NULL;
	direct = NULL;
	if ((direct = opendir(name)) == NULL)
		managerror_bis(name);
	else
	{
		while ((info = readdir(direct)) != NULL)
		{
			if (info->d_type == DT_DIR)
				if (ft_strcmp(info->d_name, ".")
						&& ft_strcmp(info->d_name, ".."))
				{
					old_name = ft_strdup(name);
					name = ft_strcat(name, "/");
					name = ft_strcat(name, info->d_name);
					ft_printf("\n%s:\n", name);
					ft_ls_recur(name, opt);
					name = old_name;
				}
		}
	}
	return (NULL);

}

static void		create_list(int *i, struct dirent *info, DIR *direct, char **list)
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

int		ft_ls_recur(char *name, t_option *opt)
{
	DIR				*direct;
	struct	dirent	*info;
	char			**list;
	int				i;
	int				j;

	direct = NULL;
	info = NULL;
	j = 0;
	if (name == NULL)
		return (0);
	if ((direct = opendir(name)) == NULL)
		managerror_bis(name);
	else
	{
		if (opt->error == 1)
			ft_printf("%s:\n", name);
		else if (opt->error == 2 || opt->l > 1)
			ft_printf("\n%s:\n", name);
		i = get_num_elem(direct, name);
		if (!(list = malloc(sizeof(char**) * i)))
			return (-1);
		j = i;
		create_list(&i, info, direct, list);
		if (opt->l >= 1)
			get_padding(name, opt, list, j);
		display_list(list, j, opt, name);
		free(list);
	}
	if (opt->Re == 1)
		name = get_new_name(name, opt);
	return (0);
}
