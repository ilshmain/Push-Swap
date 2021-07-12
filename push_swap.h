#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int 			true;
	char 			TF;
	struct s_list	*next;	
}				t_list;



int		ft_atoi(const char *str, int *flags);
void	push_swap(int argc, char **argv);
void	ft_isdigit(int c, int *flags);
int		prisvoenie_indexa(int *mas, int value, int *flags);
int		*sortirovka(int k, int *mas_new);
int		proverka(char *out, int *flags);
int		ps_validation(char **argv, int i, int *flags);
int		kolvo_simvolov(char **argv, int i, int *flags, char **out);
int		*mas_int(char **argv, int i, int k, int *flags, int **mas_1);
t_list	*sor_ind(char **argv, int *flags, int *mas, int k, int *mas_1);
int		work_with_stack(t_list *ptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		*ft_cpy(int *src, int k);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		true_false(int *mas_1, int value);
t_list 	*ft_lstnew(char *str, int *flags, int *mas, int *mas_1);
int 	max_kolvo_true(t_list *ptr, int *kolvo);
t_list 	*addlst(t_list *ptr, int *kolvo, int value);
t_list 	*index_TF(t_list *ptr);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif