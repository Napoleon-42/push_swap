/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:37:07 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/26 18:41:09 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *sa, int size)
{
	int	i;
	int	temp;

	temp = sa->stack[size - sa->size];
	i = size - sa->size;
	while (i < size - 1)
	{
		sa->stack[i] = sa->stack[i + 1];
		i++;
	}
	sa->stack[size - 1] = temp;
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_stack *sb, int size)
{
	int	i;
	int	temp;

	temp = sb->stack[size - sb->size];
	i = size - sb->size;
	while (i < size - 1)
	{
		sb->stack[i] = sb->stack[i + 1];
		i++;
	}
	sb->stack[size - 1] = temp;
	write(1, "rb\n", 3);
	return ;
}

void	rotate_ab(t_stack *sa, t_stack *sb, int size)
{
	int	i;
	int	temp;

	temp = sa->stack[size - sa->size];
	i = size - sa->size;
	while (i < size - 1)
	{
		sa->stack[i] = sa->stack[i + 1];
		i++;
	}
	sa->stack[size - 1] = temp;
	temp = sb->stack[size - sb->size];
	i = size - sb->size;
	while (i < size - 1)
	{
		sb->stack[i] = sb->stack[i + 1];
		i++;
	}
	sb->stack[size - 1] = temp;
	write(1, "rr\n", 3);
	return ;
}

void	rev_rotate_a(t_stack *sa, int size)
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
	write(1, "rra\n", 4);
	return ;
}

void	rev_rotate_b(t_stack *sb, int size)
{
	int	i;
	int	temp;

	temp = sb->stack[size - 1];
	i = size - 1;
	while (i > size - sb->size)
	{
		sb->stack[i] = sb->stack[i - 1];
		i--;
	}
	sb->stack[size - sb->size] = temp;
	write(1, "rrb\n", 4);
	return ;
}
