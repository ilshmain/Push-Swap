/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_func.c                                     :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (*flags = 4);
		if (nbr > 2147483648 && a == -1)
			return (*flags = 4);
		k++;
	}
	return (a * nbr);
}

void	ft_isdigit(int c, int *flags)
{
	if (!((c > 47 && c < 58) || c == 45 || c == 43))
		*flags = 4;
	if (c == 45 || c == 43)
		*flags = *flags + 1;
}

int	proverka(char *out, int *flags)
{
	int	i;

	i = 0;
	while (out[i])
	{
		ft_isdigit(out[i], flags);
		if (*flags > 3)
			return (0);
		i++;
	}
	*flags = 2;
	i = ft_atoi(out, flags);
	return (i);
}

int	double_value(t_list *ptr)
{
	t_list	*tmp;
	t_list	*lst;
	int		i;

	tmp = ptr;
	lst = ptr;
	while (lst)
	{
		i = 0;
		while (tmp)
		{
			if (lst->value == tmp->value)
				i++;
			if (i == 2)
				return (0);
			tmp = tmp->next;
		}
		tmp = ptr;
		lst = lst->next;
	}
	return (1);
}

void	spisok_value(char **argv, int i, int *flags, t_list **ptr)
{
	t_list	*tmp;
	int		j;
	char	**out;

	*ptr = NULL;
	while (argv[i])
	{
		j = 0;
		out = ft_split(argv[i], ' ');
		while (out[j])
		{
			tmp = ft_lstnew(flags, out[j]);
			if (*flags > 3)
				return ;
			ft_lstadd_back(ptr, tmp);
			free(out[j]);
			j++;
		}
		free(out);
		i++;
	}
	if (!double_value(*ptr))
		*flags = 3;
}
