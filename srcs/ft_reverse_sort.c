







#include "../includes/ft_ls.h"

char	**ft_reverse_sort(char **list, t_option *opt)
{
	int i;
	int j;
	char	*tmp;

	j = 0;
	while (j < opt->elem - 1)
	{
		i = 0;
		while (i < opt->elem - 1)
		{
			if (list[i + 1] && ft_strcmp(list[i], list[i + 1]) < 0)
			{
				tmp = ft_strdup(list[i]);
				list[i] = ft_strdup(list[i + 1]);
				list[i + 1] = ft_strdup(tmp);
				free(tmp);
			}
			i++;
		}
		j++;
	}
	return (list);
}
