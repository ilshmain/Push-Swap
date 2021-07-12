#include "push_swap.h"

int	work_with_stack(t_list *ptr)
{
	int kolvo;
	t_list *pem;
	int	i;


	kolvo = 0;
	i = max_kolvo_true(ptr, &kolvo);
	pem = addlst(ptr, kolvo, i);
//	while (pem)
//	{
//		printf("%d %d %d %c\n", pem->value, pem->index, pem->true, pem->TF);
//		pem = pem->next;
//	}
//	pem = index_TF(pem);
	while (ptr)
	{
		printf("%d %d %d\n", ptr->value, ptr->index, ptr->true);
		ptr = ptr->next;
	}
	printf("\n\n");
	while (pem)
	{
		printf("%d %d %d %c\n", pem->value, pem->index, pem->true, pem->TF);
		pem = pem->next;
	}
}
