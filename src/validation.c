/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_1(t_list *map, t_list *ptr, int i, int z)
{
	int	k;

	k = 1;
	while (map)
	{
		if (map->value > i)
		{
			k++;
			i = map->value;
		}
		map = map->next;
	}
	map = ptr;
	while (map->value != z)
	{
		if (map->value > i)
		{
			k++;
			i = map->value;
		}
		map = map->next;
	}
	return (k);
}

void	new(t_list *ptr)
{
	t_list	*lst;
	t_list	*map;
	int		i;
	int		z;

	lst = ptr;
	while (lst)
	{
		map = lst;
		i = lst->value;
		z = lst->value;
		lst->true = new_1(map, ptr, i, z);
		lst = lst->next;
	}
}

void	list_or_ptr(t_list **ptr)
{
	t_list	*tmp;
	int		i;

	i = 0;
	new(*ptr);
	tmp = *ptr;
	while (tmp)
	{
		if (tmp->true > i)
			i = tmp->true;
		tmp = tmp->next;
	}
}

int	TF_1(t_list **tmp, int max_true, int v)
{
	int	i;

	while (*tmp)
	{
		if ((*tmp)->true == max_true && (*tmp)->value == v)
		{
			i = (*tmp)->index;
			(*tmp)->TF = 'T';
		}
		else if ((*tmp)->index > i)
		{
			(*tmp)->TF = 'T';
			i = (*tmp)->index;
		}
		else
			(*tmp)->TF = 'F';
		*tmp = (*tmp)->next;
	}
	return (i);
}

void	TF(t_list **ptr, int max_true, int v)
{
	t_list	*tmp;
	int		i;

	tmp = *ptr;
	while (tmp->true != max_true && tmp->value != v)
		tmp = tmp->next;
	i = TF_1(&tmp, max_true, v);
	tmp = *ptr;
	while (tmp->true != max_true && tmp->value != v)
	{
		if (tmp->index > i)
		{
			tmp->TF = 'T';
			i = tmp->index;
		}
		else
			tmp->TF = 'F';
		tmp = tmp->next;
	}
}
