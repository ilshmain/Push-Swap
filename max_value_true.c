#include "push_swap.h"

int 	max_kolvo_true(t_list *ptr, int *kolvo)
{
	int i;
	int v;

	i = ft_lstsize(ptr);
	v = 0;
	while (i > 0)
	{
		if (ptr->true > *kolvo)
		{
			*kolvo = ptr->true;
			v = ptr->value;
		}
		if (ptr->true == *kolvo && *kolvo != 0)
		{
			if (ptr->value > v)
				v = ptr->value;
		}
		ptr = ptr->next;
		i--;
	}
	return (v);
}

t_list 	*index_TF(t_list *ptr)
{
	int i;

	i = 0;
	while (ptr)
	{
		if (i != 0)
		{
			if (ptr->value > i)
				ptr->TF = 'T';
		}
		if (i == 0)
			ptr->TF = 'T';
		i = ptr->value;
		ptr = ptr->next;
	}
	return (ptr);
}

t_list 	*addlst(t_list *ptr, int *kolvo, int value)
{
	t_list	*tmp;

	while (ptr->true != kolvo && ptr->value != value)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (!tmp)
			return (NULL);
		tmp->value = ptr->value;
		tmp->true = ptr->true;
		tmp->index = ptr->index;
		tmp->next = NULL;
		ft_lstadd_back(&ptr, tmp);
		ptr = ptr->next;
	}
//	while (ptr)
//	{
//		printf("%d %d %d\n", ptr->value, ptr->index, ptr->true);
//		ptr = ptr->next;
//	}
	return (ptr);
}


