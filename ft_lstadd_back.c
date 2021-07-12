#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ending;

	if (!lst)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		ending = ft_lstlast(*lst);
		ending->next = new;
	}
}

t_list 	*ft_lstnew(char *str, int *flags, int *mas, int *mas_1)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->value = proverka(str, flags);
	tmp->index = prisvoenie_indexa(mas, tmp->value, flags);
	tmp->true = true_false(mas_1, tmp->value);
	tmp->next = NULL;
	return (tmp);
}