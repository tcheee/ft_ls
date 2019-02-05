








#include "../includes/ft_ls.h"

static int		check_option(char *str)
{
	int j;

	j = 0;
	if (str[j] == '-')
	{
		j++;
		while (str[j] != '\0')
		{
			if (str[j] != 'R' && str[j] != 'a' && str[j] != 'l'
					&& str[j] != 'r' && str[j] != 't')
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}

int		check_error_ls(int ac, char **av, t_option *opt)
{
	DIR		*direct;
	int		i;

	i = 1;
	opt->error = 0;
	direct = NULL;
	while (av[i] && check_option(av[i]) == 1)
		i++;
	while (i < ac)
	{
		if (av[i])
		{
			if ((direct = opendir(av[i])) == NULL)
			{
				opt->error = 1;
				managerror(av[i], opt);
			}
			i++;
		}
	}
	return (0);
}
