/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Three_argc.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back(t_list **stack, int index, char *str)
{
	t_list	*lst;

	while ((*stack)->index != index)
	{
		lst = per_tmp(ft_lstlast(*stack));
		ft_lstadd_front(stack, lst);
		del(stack);
		write(1, str, 4);
	}
}

void	mov(t_list **stack, int index, char *str)
{
	t_list	*tmp;
	t_list	*res;

	while ((*stack)->index != index)
	{
		res = *stack;
		tmp = per_tmp(*stack);
		*stack = (*stack)->next;
		res->next = NULL;
		ft_lstclear(&res);
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
		write (1, str, 3);
	}
}

void	three_arguments_1(t_list *tmp1, t_list **ptr)
{
	int	i;

	i = 1;
	while (tmp1->index != 0)
	{
		i++;
		tmp1 = tmp1->next;
	}
	if (i == 3)
		back(ptr, 0, "rra\n");
	else
		mov(ptr, 0, "ra\n");
}

void	three_arguments(t_list **ptr)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = *ptr;
	three_arguments_1(tmp1, ptr);
	tmp1 = (*ptr)->next;
	if (tmp1->index != 1)
	{
		tmp = per_tmp(tmp1);
		(*ptr)->next = tmp;
		tmp->next = tmp1->next;
		tmp1->next = NULL;
		write (1, "rra\n", 4);
		write (1, "sa\n", 3);
	}
	ft_lstclear(ptr);
}
