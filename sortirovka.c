#include "push_swap.h"

int	prisvoenie_indexa(int *mas, int value, int *flags)
{
	int	j;
	int k;

	j = 0;
	k = 0;
	*flags = 1;
	while (mas[j])
	{
		if (mas[j] == value)
		{
			*flags = *flags + 1;
			k = j;
		}
		j++;
	}
	return (k);
}

int	*sortirovka(int k, int *mas_new)
{
	int	i;
	int	per;
	int	z;
	int	*mas;

	i = 1;
	z = 1;
	mas = malloc(sizeof(int) * (k + 1));
	mas = mas_new;
	while (i <= k)
	{
		while (z > 0)
		{
			if (mas[z] < mas[z - 1])
			{
				per = mas[z - 1];
				mas[z - 1] = mas[z];
				mas[z] = per;
			}
			z--;
		}
		i++;
		z = i;
	}

	return (mas);
}

int	*mas_int(char **argv, int i, int k, int *flags, int **mas_1)
{
	int		*mas;
	int		j;
	int		z;
	char	**out;

	j = 0;
	z = 0;
	mas = malloc(sizeof(int) * (k + 1));
	while (argv[i])
	{
		out = ft_split(argv[i], ' ');
		while (out[j])
		{
			mas[z] = proverka(out[j], flags);
			j++;
			z++;
		}
		j = 0;
		i++;
		free(out[j]);
	}
	free(out);
	*mas_1 = ft_cpy(mas, k);
	sortirovka(k, mas);
	return (mas);
}