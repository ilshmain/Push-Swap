/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                        :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	with_b_in_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*lst;

	lst = NULL;
	tmp = per_tmp(*stack_b);
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
	lst = *stack_b;
	free(lst);
	*stack_b = (*stack_b)->next;
}

void	stack_mov(t_list **stack, int value, char *str)
{
	t_list	*tmp;
	t_list	*res;

	while ((*stack)->value != value)
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

void	mov_rr(t_list **stack_a, t_list **stack_b, int a_value, int b_value)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*lst;
	t_list	*lst1;

	lst = NULL;
	lst1 = NULL;
	while ((*stack_a)->value != a_value && (*stack_b)->value != b_value)
	{
		tmp = per_tmp(*stack_a);
		tmp1 = per_tmp(*stack_b);
		ft_lstadd_back(stack_a, tmp);
		ft_lstadd_back(stack_b, tmp1);
		lst1 = *stack_b;
		free(lst1);
		*stack_b = (*stack_b)->next;
		lst = *stack_a;
		free(lst);
		*stack_a = (*stack_a)->next;
		write (1, "rr\n", 3);
	}
	if ((*stack_b)->value == b_value)
		stack_mov(stack_a, a_value, "ra\n");
	if ((*stack_a)->value == a_value)
		stack_mov(stack_b, b_value, "rb\n");
}

void	stack_back(t_list **stack, int value, char *str)
{
	t_list	*lst;

	while ((*stack)->value != value)
	{
		lst = per_tmp(ft_lstlast(*stack));
		ft_lstadd_front(stack, lst);
		del(stack);
		write(1, str, 4);
	}
}

void	back_rrr(t_list **stack_a, t_list **stack_b, int a_value, int b_value)
{
	t_list	*tmp;
	t_list	*lst;

	while ((*stack_b)->value != b_value && (*stack_a)->value != a_value)
	{
		tmp = per_tmp(ft_lstlast(*stack_b));
		lst = per_tmp(ft_lstlast(*stack_a));
		ft_lstadd_front(stack_a, lst);
		ft_lstadd_front(stack_b, tmp);
		del(stack_b);
		del(stack_a);
		write (1, "rrr\n", 4);
	}
	if ((*stack_b)->value == b_value && (*stack_a)->value != a_value)
		stack_back(stack_a, a_value, "rra\n");
	if ((*stack_a)->value == a_value && (*stack_b)->value != b_value)
		stack_back(stack_b, b_value, "rrb\n");
}
