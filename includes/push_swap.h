/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: fmint <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 08:43:15 by fmint             #+#    #+#             */
/*   Updated: 2021/08/01 08:50:18 by fmint            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				true;
	int				steps;
	int				dop_value;
	char			TF;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *str, int *flags);
void	ft_isdigit(int c, int *flags);
int		proverka(char *out, int *flags);
int		double_value(t_list *ptr);
void	spisok_value(char **argv, int i, int *flags, t_list **ptr);
int		new_1(t_list *map, t_list *ptr, int i, int z);
void	new(t_list *ptr);
void	list_or_ptr(t_list **ptr);
int		TF_1(t_list **tmp, int max_true, int v);
void	TF(t_list **ptr, int max_true, int v);
void	back(t_list **stack, int index, char *str);
void	mov(t_list **stack, int index, char *str);
void	three_arguments_1(t_list *tmp1, t_list **ptr);
void	three_arguments(t_list **ptr);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	del(t_list **ptr);
int		get_list_size(t_list *stack);
t_list	*ft_lstnew(int *flags, char *str);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	start_begin(t_list **stack_a, t_list **stack_b, int kolvo_false);
void	stack_a_b(t_list **stack_a, int len, int kolvo_true);
void	steps(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
void	last_stack_sort(t_list **stack_a);
t_list	*use_method2(t_list *stack_b, int steps);
int		method_b(t_list **stack_b, t_list *per, int max_step_b);
int		method_a(t_list **stack_a, t_list *per, int max_step_a);
void	method_selected(t_list **stack_a, t_list **stack_b, t_list *per);
void	from_st_a_to_st_b(t_list **stack_a, t_list **stack_b, int steps);
int		TF_index(t_list **ptr);
void	TF_index1(t_list **ptr);
void	sortirovka_1(t_list **map, t_list **tmp, int *i);
int		sortirovka(t_list **ptr, int *v);
t_list	*per_tmp(t_list *ptr);
void	work_with_stack(t_list **ptr, int max_true);
int		ps_validation(char **argv, int i, int *flags, int v);
void	push_swap(int argc, char **argv);
void	sum_steps_stack_a_or_b(t_list **stack_b, int len_b, int a, int b);
int		last_steps_1(t_list **pst, t_list **tmp, t_list **stack_a);
int		last_steps_2(t_list **stack_a, t_list **pst, t_list **tmp, int *i);
t_list	*last_steps(t_list **stack_a, t_list *tmp);
void	sum_steps_stack_a_b(t_list **stack_a, t_list **stack_b, int *i);
void	with_b_in_a(t_list **stack_a, t_list **stack_b);
void	stack_mov(t_list **stack, int value, char *str);
void	mov_rr(t_list **stack_a, t_list **stack_b, int a_value, int b_value);
void	stack_back(t_list **stack, int value, char *str);
void	back_rrr(t_list **stack_a, t_list **stack_b, int a_value, int b_value);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);

#endif