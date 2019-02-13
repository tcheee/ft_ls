








#include "../includes/ft_ls.h"

int		get_num_elem(DIR *direct, char *name, t_option *opt)
{
	int i;

	i = 0;
	direct = opendir(name);
	while (readdir(direct) != NULL)
		i++;
	closedir(direct);
	opt->elem = i;
	return (i);
}
