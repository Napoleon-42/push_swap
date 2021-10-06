/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:27:50 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/26 19:15:37 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_ab(t_stack *sa, t_stack *sb, int size)
{
	int	i;
	int	temp;

	temp = sa->stack[size - 1];
	i = size - 1;
	while (i > size - sa->size)
	{
		sa->stack[i] = sa->stack[i - 1];
		i--;
	}
	sa->stack[size - sa->size] = temp;
	temp = sb->stack[size - 1];
	i = size - 1;
	while (i > size - sb->size)
	{
		sb->stack[i] = sb->stack[i - 1];
		i--;
	}
	sb->stack[size - sb->size] = temp;
	write (1, "rrr\n", 4);
	return ;
}

void	rotate_n(t_stack *s, int size, int n, char key)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (key == 'a')
			rotate_a(s, size);
		else
			rotate_b(s, size);
		i++;
	}
	return ;
}

void	rev_rotate_n(t_stack *s, int size, int n, char key)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (key == 'a')
			rev_rotate_a(s, size);
		else
			rev_rotate_b(s, size);
		i++;
	}
	return ;
}

void	execute_utils_push(t_stack *data, int size, char *str, int i)
{
	if (str[i + 1] == 'b')
		push_b(&(data[0]), &(data[1]), size);
	if (str[i + 1] == 'a')
		push_a(&(data[0]), &(data[1]), size);
	return ;
}
