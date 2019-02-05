









#include "../includes/ft_ls.h"

static void		read_dir(struct dirent *info, DIR *direct, t_option *opt)
{
	while ((info = readdir(direct)) != NULL)
	{
		if (opt->a == 0)
		{
			if ((info->d_name)[0] != '.')
			{
				if (opt->l == 0)
					ft_printf("%s\n", info->d_name);
			}
		}
		else if (opt->a == 1)
		{
			if (opt->l == 0)
				ft_printf("%s\n", info->d_name);
		}
	}
}

int		ft_list(int ac, char **av, t_option *opt, int *i)
{
	DIR				*direct;
	struct	dirent	*info;

	direct = NULL;
	info = NULL;
	if (*i == ac)
	{
		if ((direct = opendir("./")) == NULL)
			return (-1); //manage_errror
		read_dir(info, direct, opt);
	}
	else
	{
		while (*i < ac)
		{
			if ((direct = opendir(av[*i])) == NULL)
				return (-1); //manage_error();
			read_dir(info, direct, opt);
			(*i)++;
		}
	}
	closedir(direct);
	return (0);
}
