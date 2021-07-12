#include "push_swap.h"

int	ps_validation(char **argv, int i, int *flags)
{
	int		k;
	int		*mas;
	char	**out;
	t_list	*ptr;
	int		*mas_1;
	int 	j;

	j = 0;
	k = kolvo_simvolov(argv, i, flags, out);
	if (*flags > 3)
		return (0);
	mas = mas_int(argv, i, k, flags, &mas_1);
	ptr = sor_ind(argv, flags, mas, k, mas_1);
	if (*flags == 2)
		work_with_stack(ptr);
	else
		return (0);
	return (1);
}
