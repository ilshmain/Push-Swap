#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	int		i;
	int		flags;

	i = 1;
	flags = 2;
	if (argc == 1)
		exit(1);
	if (!ps_validation(argv, i, &flags))
	{
		write (1, "Error", 5);
		return ;
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
