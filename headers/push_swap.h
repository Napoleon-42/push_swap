/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:10:42 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/27 16:39:32 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}				t_stack;

/* UTILS */
void		print_intarr(int *arr, int size);
void		print(t_stack a, t_stack b, int size);
t_stack		*initialize(int ac, char **av);
int			stack_check(t_stack a, int size);
void		execute(t_stack *a, t_stack *b, int size, char *commands);
void		execute_utils_push(t_stack *data, int size, char *str, int i);
void		rev_under_2(t_stack *b);
void		under_5_utils3(t_stack *sa, t_stack *sb);
void		under_5_utils2(t_stack *sa, t_stack *sb);
void		under_5_utils(t_stack *sa, t_stack *sb);

/* INTPUT_CHECK */
int			av_check(char **strs, int ac);
int			doubles_check(int *a, int size);
int			error_exit(void);

/* BINARY_SORT */
void		binary_sort(t_stack *a, t_stack *b, int size);
void		re_arrange(int *sorted, int *arr, int size);
int			max_l_inbin(int size);

/* RADIX_SORT */
int			max_lenght(int *arr, int size);
int			*radix_sort(t_stack arr, int max_lenght); //DONE AND TESTED

/* OPERATIONS */
void		push_a(t_stack *sa, t_stack *sb, int size); //DONE AND TESTED
void		push_b(t_stack *sa, t_stack *sb, int size); //DONE AND TESTED
void		swap_a(t_stack *sa, int size); //DONE AND TESTED
void		swap_b(t_stack *sb, int size); //DONE AND TESTED
void		swap_ab(t_stack *sa, t_stack *sb, int size); //DONE AND TESTED
void		rotate_a(t_stack *sa, int size); //DONE AND TESTED
void		rotate_b(t_stack *sb, int size); //DONE AND TESTED
void		rotate_ab(t_stack *sa, t_stack *sb, int size); //DONE AND TESTED
void		rev_rotate_a(t_stack *sa, int size); //DONE AND TESTED
void		rev_rotate_b(t_stack *sb, int size); //DONE AND TESTED
void		rev_rotate_ab(t_stack *sa, t_stack *sb, int size); //DONE AND TESTED
void		rotate_n(t_stack *s, int size, int n, char key);
void		rev_rotate_n(t_stack *s, int size, int n, char key);

void		under_5(t_stack *sa, t_stack *sb, int size);
void		under_3(t_stack *sa, int size);

/* IS_INT */
char		is_int(long long nbr);

#endif
