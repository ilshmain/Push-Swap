/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortirovka.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	TF_index(t_list **ptr)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *ptr;
	while (tmp->index != i)
		tmp = tmp->next;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->index == i + 1)
			i = tmp->index;
		else
			return (i + 1);
		tmp = tmp->next;
	}
	return (i + 1);
}

void	TF_index1(t_list **ptr)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *ptr;
	while (tmp->index != i)
	{
		tmp->TF = 'F';
		tmp = tmp->next;
	}
	tmp->TF = 'T';
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->index == i + 1)
		{
			i = tmp->index;
			tmp->TF = 'T';
		}
		else
			tmp->TF = 'F';
		tmp = tmp->next;
	}
}

void	sortirovka_1(t_list **map, t_list **tmp, int *i)
{
	while (*map)
	{
		if ((*tmp)->value > (*map)->value)
			(*i)++;
		*map = (*map)->next;
	}
}

int	sortirovka(t_list **ptr, int *v)
{
	t_list	*tmp;
	t_list	*map;
	int		i;
	int		k;

	k = 0;
	tmp = *ptr;
	while (tmp)
	{
		i = 0;
		map = *ptr;
		sortirovka_1(&map, &tmp, &i);
		if (tmp->true > k)
		{
			k = tmp->true;
			*v = tmp->value;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
	return (k);
}
