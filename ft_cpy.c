#include "push_swap.h"

int	*ft_cpy(int *src, int k)
{
	int	*dst;
	int	i;


	dst = malloc(sizeof(int) * (k + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int true_false(int *mas_1, int value)
{
	int i;
	int	k;
	int value1;

	i = 0;
	k = 1;
	value1 = value;
	while (value != mas_1[i])
		i++;
	while (mas_1[i] && mas_1[i + 1])
	{
		i++;
		if (mas_1[i] > value)
		{
			k++;
			value = mas_1[i];
		}
		i++;
	}
	i = 0;
	while (mas_1[i] != value1)
	{
		if (mas_1[i] > value)
		{
			k++;
			value = mas_1[i];
		}
		i++;
	}
	return (k);
}
