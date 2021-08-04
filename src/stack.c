/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                               :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_begin(t_list **stack_a, t_list **stack_b, int kolvo_false)
{
	t_list	*tmp;
	t_list	*lst;

	lst = NULL;
	while (kolvo_false != 0)
	{
		tmp = per_tmp(*stack_a);
		if ((*stack_a)->TF == 'T')
		{
			ft_lstadd_back(stack_a, tmp);
			write(1, "ra\n", 3);
			lst = *stack_a;
			free(lst);
			*stack_a = (*stack_a)->next;
		}
		else
		{
			ft_lstadd_front(stack_b, tmp);
			write(1, "pb\n", 3);
			lst = *stack_a;
			free(lst);
			kolvo_false--;
			(*stack_a) = (*stack_a)->next;
		}
	}
}

void	last_stack_sort(t_list **stack_a)
{
	t_list	*mpr;
	int		i;
	int		k;

	k = 1;
	mpr = *stack_a;
	while (mpr->index != 0)
	{
		k++;
		mpr = mpr->next;
	}
	i = get_list_size(*stack_a);
	if (k <= i)
		stack_mov(stack_a, mpr->value, "ra\n");
	else
		stack_back(stack_a, mpr->value, "rra\n");
}

void	steps(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	int	i;
	int	len;

	len = len_b + len_a;
	while (*stack_b)
	{
		i = 100000;
		len_a = ft_lstsize(*stack_a);
		len_b = ft_lstsize(*stack_b);
		sum_steps_stack_a_or_b(stack_b, len_b, 0, 1);
		sum_steps_stack_a_or_b(stack_a, len_a, 0, 0);
		sum_steps_stack_a_b(stack_a, stack_b, &i);
		from_st_a_to_st_b(stack_a, stack_b, i);
	}
	i = ft_lstsize(*stack_a);
	last_stack_sort(stack_a);
}

void	stack_a_b(t_list **stack_a, int len, int kolvo_true)
{
	t_list	*stack_b;
	int		kolvo_false;

	stack_b = NULL;
	kolvo_false = len - kolvo_true;
	if (kolvo_false == 0)
		last_stack_sort(stack_a);
	else
	{
		start_begin(stack_a, &stack_b, kolvo_false);
		len = ft_lstsize(*stack_a);
		kolvo_false = ft_lstsize(stack_b);
		steps(stack_a, &stack_b, len, kolvo_false);
	}
	ft_lstclear(stack_a);
	ft_lstclear(&stack_b);
}
