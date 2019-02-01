/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:29:18 by tcherret          #+#    #+#             */
/*   Updated: 2019/02/01 19:42:07 by tcherret         ###   ########.fr       */
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

typedef struct	s_option
{
	int	l;
	int	a;
	int	Re;
	int	t;
	int	r;
}				t_option;

int				ft_inspect(char *av);
void			get_option(int ac, char **av, t_option *opt);

#endif
