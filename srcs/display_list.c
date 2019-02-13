







#include "../includes/ft_ls.h"

void		display_list(char **list, int j, t_option *opt, char *name)
{
	int i;
	char	*stock;

	stock = ft_strdup(name);
	if (opt->t == 1 && opt->r == 1)
		ft_rtime_sort(stock, list, opt);
	else if (opt->t == 1)
		list = ft_time_sort(stock, list, opt);
	else if (opt->r == 1)
		list = ft_reverse_sort(list, opt);
	else
		list = ft_sort(list, opt);
	i = 0;
	if (opt->l >= 1)
		ft_printf("total %d\n", opt->tot);
	while (i < j)
	{
		if ((opt->a && list[i][0] == '.') || list[i][0] != '.')
			opt->l == 0 ? ft_printf("%s\n", list[i]) : ft_inspect(stock, list[i], opt);
		//free(list[i]);
		i++;
	}
	free(stock);
}
