/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:29:18 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/20 17:24:47 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# define BUF_SIZE 1024

typedef struct	s_option
{
	int	l;
	int	a;
	int	re;
	int	t;
	int	r;
	int	error;
	int tot;
	int	pad1;
	int	pad2;
	int	nb;
	int	elem;
	int	dev;
	int	rep;
	int	aff;
	int	slash;
	int	in;
}				t_option;

int				ft_inspect(char *path, char *name, t_option *opt);
void			get_option(int ac, char **av, t_option *opt, int *i);
int				ft_list(int ac, char **av, t_option *opt, int *i);
int				ft_ls_recur(char *name, t_option *opt);
int				managerror(char *name);
int				managerror_bis(char *name);
int				managerror_bis1(char *name);
int				managerror_file(char *name, t_option *opt);
char			**ft_sort(char **list, int nb);
char			**ft_reverse_sort(char **list, int nb);
char			**ft_rtime_sort(char *path, char **list, t_option *opt);
char			**ft_time_sort(char *path, char **list, t_option *opt);
char			**ft_time_sort_param(char **list, int nb);
char			**ft_rtime_sort_param(char **list, int nb);
int				check_error_ls(int ac, char **av, t_option *opt);
int				check_error_ls_param(int ac, char **av,
		t_option *opt, int total);
int				get_padding(char *name, t_option *opt, char **list, int j);
void			display_list(char **list, int j, t_option *opt, char *name);
int				get_num_elem(DIR *direct, char *name, t_option *opt);
void			create_list(int *i, struct dirent *info,
		DIR *direct, char **list);
int				get_num_arg(int ac, char **av);
void			get_mode(struct stat *info, t_option *opt, char *s1);
void			get_time(struct stat *info, t_option *opt, char *s2);
char			*get_new_name(char *name, char **list, t_option *opt);

#endif
