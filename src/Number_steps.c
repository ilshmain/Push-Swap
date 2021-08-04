/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number_steps.c                                        :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sum_steps_stack_a_or_b(t_list **stack_b, int len_b, int a, int b)
{
	t_list	*pts;
	int		k;

	pts = *stack_b;
	k = len_b / 2;
	if ((len_b % 2) != 0)
		k = k + 1;
	while (pts && a <= k - 1)
	{
		pts->steps = a + b;
		pts = pts->next;
		a++;
	}
	a = len_b - a;
	while (pts)
	{
		pts->steps = a + b;
		pts = pts->next;
		a--;
	}
}

int	last_steps_1(t_list **pst, t_list **tmp, t_list **stack_a)
{
	t_list	*stm;

	stm = per_tmp(ft_lstlast(*stack_a));
	if ((*tmp)->value > stm->value && (*tmp)->value < (*pst)->value)
	{
		(*tmp)->dop_value = (*pst)->value;
		free(stm);
		return (1);
	}
	free(stm);
	return (0);
}

int	last_steps_2(t_list **stack_a, t_list **pst, t_list **tmp, int *i)
{
	*i = (*pst)->value;
	*pst = (*pst)->next;
	while (*pst)
	{
		if ((*tmp)->value > *i && (*tmp)->value < (*pst)->value)
		{
			(*tmp)->steps = (*tmp)->steps + (*pst)->steps;
			(*tmp)->dop_value = (*pst)->value;
			return (1);
		}
		*i = (*pst)->value;
		*pst = (*pst)->next;
	}
	*pst = *stack_a;
	*i = (*pst)->value;
	return (0);
}

t_list	*last_steps(t_list **stack_a, t_list *tmp)
{
	t_list	*pst;
	int		i;
	int		k;

	pst = *stack_a;
	if (last_steps_1(&pst, &tmp, stack_a))
		return (tmp);
	if (last_steps_2(stack_a, &pst, &tmp, &i))
		return (tmp);
	k = pst->steps;
	pst = pst->next;
	while (pst)
	{
		if (pst->value < i)
		{
			i = pst->value;
			k = pst->steps;
		}
		pst = pst->next;
	}
	tmp->steps = tmp->steps + k;
	tmp->dop_value = i;
	return (tmp);
}

void	sum_steps_stack_a_b(t_list **stack_a, t_list **stack_b, int *i)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack_b;
	while (lst)
	{
		tmp = per_tmp(lst);
		tmp = last_steps(stack_a, tmp);
		lst->steps = tmp->steps;
		lst->dop_value = tmp->dop_value;
		free(tmp);
		if (lst->steps < (*i))
			*i = lst->steps;
		lst = lst->next;
	}
}
