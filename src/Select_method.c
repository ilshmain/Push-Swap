/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Select_method.c                                       :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*per_tmp(t_list *ptr)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->value = ptr->value;
	tmp->true = ptr->true;
	tmp->index = ptr->index;
	tmp->TF = ptr->TF;
	tmp->dop_value = ptr->dop_value;
	tmp->steps = ptr->steps;
	tmp->next = NULL;
	return (tmp);
}

void	work_with_stack(t_list **ptr, int max_true)
{
	int	len;

	len = ft_lstsize(*ptr);
	stack_a_b(ptr, len, max_true);
}
