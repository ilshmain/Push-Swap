/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                           :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_validation(char **argv, int i, int *flags, int v)
{
	t_list	*ptr;
	int		max_true;
	int		index;
	int		arguments;

	spisok_value(argv, i, flags, &ptr);
	if (*flags != 2)
		return (0);
	arguments = ft_lstsize(ptr);
	list_or_ptr(&ptr);
	max_true = sortirovka(&ptr, &v);
	index = TF_index(&ptr);
	if (arguments <= 3 && arguments != 1)
		three_arguments(&ptr);
	else
	{
		if (max_true > index)
			TF(&ptr, max_true, v);
		else
			TF_index1(&ptr);
		work_with_stack(&ptr, max_true);
	}
	return (1);
}

void	push_swap(int argc, char **argv)
{
	int		i;
	int		flags;

	i = 1;
	flags = 2;
	if (argc == 1)
		 exit(1);
	if (!ps_validation(argv, i, &flags, 0))
	{
		write (1, "Error\n", 6);
		return ;
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
