/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Struct_func_1.c                                       :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(t_list **ptr)
{
	t_list	*per;
	int		i;

	i = ft_lstsize(*ptr);
	per = *ptr;
	while (i - 1 > 1)
	{
		per = per->next;
		i--;
	}
	free(per->next);
	per->next = NULL;
}

int	get_list_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i / 2 + i % 2);
}

t_list	*ft_lstnew(int *flags, char *str)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->value = proverka(str, flags);
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		lst->value = 0;
		lst->steps = 0;
		lst->TF = 0;
		lst->index = 0;
		lst->true = 0;
		lst->dop_value = 0;
		free(lst);
	}
}

void	ft_lstclear(t_list **lst)
{
	if (lst && *lst)
	{
		if (*lst)
		{
			ft_lstclear(&(*lst)->next);
			ft_lstdelone((*lst));
			*lst = NULL;
		}
	}
}
