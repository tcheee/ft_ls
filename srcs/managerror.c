







#include "../includes/ft_ls.h"

int		managerror(char *name, t_option *opt)
{
	DIR		*direct;

	direct = NULL;
	if ((direct = opendir(name)) == NULL)
	{
		if (errno == ENOTDIR)
		{
			opt->error = 2;
			ft_printf("%s\n", name);
			return (0);
		}
		else
			ft_printf("%s: %s: %s \n", "ft_ls", name, strerror(errno));;
	}
	return (-1);
}

int		managerror_bis(char *name)
{
	DIR		*direct;

	direct = NULL;
	if ((direct = opendir(name)) == NULL)
		return (-1);
	return (-1);
}
