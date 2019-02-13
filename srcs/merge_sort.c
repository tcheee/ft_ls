







#include "../includes/ft_ls.h"

char	**merge(char **L, char **R)
{


}

char	**merge_sort(char **list, int size)
{
	int i;
	int j;
	int m;
	char **L;
	char **R;

	if (size <= 1)
		return (list);
	else
	{
		m = size / 2;
		i = 0;
		j = 0;
		if (!(L = malloc(sizeof(char**) * m)))
			return (NULL);
		while (i < m)
		{
			L[i] = ft_strdup(list[i]);
			i++;
		}
		if (!(R = malloc(sizeof(char**) * m)))
			return (NULL);
		m = i;
		while (i < size)
		{
			R[j] = ft_strdup(list[i]);
			i++;
			j++;
		}
		merge(merge_sort(L, m), merge_sort(R, j));
		//free(L);
		//free(R);
		return (list);
	}
}
