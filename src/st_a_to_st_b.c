/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_a_to_b.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*use_method2(t_list *stack_b, int steps)
{
	t_list	*lst;
	t_list	*per;

	per = NULL;
	lst = stack_b;
	while (lst)
	{
		if (lst->steps == steps)
		{
			per = per_tmp(lst);
			break ;
		}
		lst = lst->next;
	}
	return (per);
}

int	method_b(t_list **stack_b, t_list *per, int max_step_b)
{
	int		i;
	t_list	*lst;

	i = 1;
	lst = *stack_b;
	while (lst->steps != per->steps)
	{
		i++;
		if (i > max_step_b)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	method_a(t_list **stack_a, t_list *per, int max_step_a)
{
	int		i;
	t_list	*lst;

	i = 1;
	lst = *stack_a;
	while (lst->value != per->dop_value)
	{
		i++;
		if (i > max_step_a)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	method_selected(t_list **stack_a, t_list **stack_b, t_list *per)
{
	int	max_step_a;
	int	max_step_b;
	int	a;
	int	b;

	max_step_a = get_list_size(*stack_a);
	max_step_b = get_list_size(*stack_b);
	a = method_a(stack_a, per, max_step_a);
	b = method_b(stack_b, per, max_step_b);
	if (a == 0 && b == 0)
		back_rrr(stack_a, stack_b, per->dop_value, per->value);
	else if (a == 1 && b == 1)
		mov_rr(stack_a, stack_b, per->dop_value, per->value);
	else if (a == 0 && b == 1)
	{
		stack_mov(stack_b, per->value, "rb\n");
		stack_back(stack_a, per->dop_value, "rra\n");
	}
	else
	{
		stack_mov(stack_a, per->dop_value, "ra\n");
		stack_back(stack_b, per->value, "rrb\n");
	}
}

void	from_st_a_to_st_b(t_list **stack_a, t_list **stack_b, int steps)
{
	t_list	*per;

	per = use_method2(*stack_b, steps);
	method_selected(stack_a, stack_b, per);
	free(per);
	with_b_in_a(stack_a, stack_b);
}
