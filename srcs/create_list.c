









#include "../includes/ft_ls.h"

void		create_list(int *i, struct dirent *info, DIR *direct, char **list)
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
