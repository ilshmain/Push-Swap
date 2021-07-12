#include "push_swap.h"

int	ft_atoi(const char *str, int *flags)
{
	long	nbr;
	int		k;
	int		a;

	nbr = 0;
	k = 0;
	a = 1;
	while (str[k] == 32 || (str[k] > 8 && str[k] < 14))
		k++;
	if (str[k] == '+' || str[k] == '-')
	{
		if (str[k] == '-')
			a = -a;
		k++;
	}
	while (str[k] > 47 && str[k] < 58)
	{
		nbr = nbr * 10 + (str[k] - '0');
		if (nbr > 2147483647 && a == 1)
			return (*flags = -1);
		if (nbr > 2147483648 && a == -1)
			return (*flags = 0);
		k++;
	}
	return (a * nbr);
}

void	ft_isdigit(int c, int *flags)
{
	if (!((c > 47 && c < 58) || c == 45 || c == 43))
		*flags = 5;
}

int	proverka(char *out, int *flags)
{
	int	i;

	i = 0;
	while (out[i])
	{
		ft_isdigit(out[i], flags);
		if (out[i] == '+' || out[i] == '-')
			*flags = *flags + 1;
		if (*flags > 3)
			return (0);
		i++;
	}
	*flags = 2;
	i = ft_atoi(out, flags);
	return (i);
}

int	kolvo_simvolov(char **argv, int i, int *flags, char **out)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (argv[i])
	{
		out = ft_split(argv[i], ' ');
		while (out[j])
		{
			if (!proverka(out[j], flags))
				return (0);
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (k - 1);
}

t_list	*sor_ind(char **argv, int *flags, int *mas, int k, int *mas_1)
{
	t_list	*ptr;
	char	**out;
	t_list	*tmp;
	int		j;
	int 	i;

	j = 0;
	i = 1;
	k = k + 1;
	ptr = NULL;
	while (argv[i])
	{
		out = ft_split(argv[i], ' ');
		while (out[j])
		{
			tmp = NULL;
			tmp = ft_lstnew(out[j], flags, mas, mas_1);
			ft_lstadd_back(&ptr, tmp);
			if (*flags != 2)
				return (0);
			j++;
		}
		j = 0;
		i++;
		free(out);
	}
	return (ptr);
}



