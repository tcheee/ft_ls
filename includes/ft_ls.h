/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:29:18 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/07 17:38:18 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/includes/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_option
{
	int	l;
	int	a;
	int	Re;
	int	t;
	int	r;
	int	error;
	int tot;
	int	pad1;
	int	pad2;
	int	nb;
}				t_option;

int				ft_inspect(char *path, char *name, t_option *opt);
void			get_option(int ac, char **av, t_option *opt, int *i);
int				ft_list(int ac, char **av, t_option *opt, int *i);
int				ft_ls_recur(char *name, t_option *opt);
int				managerror(char *name, t_option *opt);
int				managerror_bis(char *name);
char			**ft_sort(char **list);
int				check_error_ls(int ac, char **av, t_option *opt);
int				get_padding(char *name, t_option *opt, char **list, int j);

#endif
