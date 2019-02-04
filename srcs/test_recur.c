







#include "../includes/ft_ls.h"

int		ft_list_test_recur(int ac, char **av, t_option *opt, int *i)
{
	DIR				*direct;
	struct	dirent	*info;

	direct = NULL;
	info = NULL;
	while (*i < ac)
	{
		if ((direct = opendir(av[*i])) == NULL)
			return (-1); //manage_error();
		while ((info = readdir(direct)) != NULL)
		{
			if (opt->a == 0)
			{
				if ((info->d_name)[0] != '.')
					ft_printf("%s\n", info->d_name);
			}
			else if (opt->a == 1)
				ft_printf("%s\n", info->d_name);
			(*i)++;
		}
	}
	closedir(direct);
	return (0);
}
