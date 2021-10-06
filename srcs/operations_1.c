/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:10:39 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/26 18:40:40 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *sa, t_stack *sb, int size)
{
	sa->size++;
	sa->stack[size - sa->size] = sb->stack[size - sb->size];
	sb->size--;
	write(1, "pa\n", 3);
	return ;
}

void	push_b(t_stack *sa, t_stack *sb, int size)
{
	sb->size++;
	sb->stack[size - sb->size] = sa->stack[size - sa->size];
	sa->size--;
	write(1, "pb\n", 3);
	return ;
}

void	swap_a(t_stack *sa, int size)
{
	int	temp;

	temp = sa->stack[size - sa->size];
	sa->stack[size - sa->size] = sa->stack[size - sa->size + 1];
	sa->stack[size - sa->size + 1] = temp;
	write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_stack *sb, int size)
{
	int	temp;

	temp = sb->stack[size - sb->size];
	sb->stack[size - sb->size] = sb->stack[size - sb->size + 1];
	sb->stack[size - sb->size + 1] = temp;
	write(1, "sb\n", 3);
	return ;
}

void	swap_ab(t_stack *sa, t_stack *sb, int size)
{
	int	temp;

	temp = sa->stack[size - sa->size];
	sa->stack[size - sa->size] = sa->stack[size - sa->size + 1];
	sa->stack[size - sa->size + 1] = temp;
	temp = sb->stack[size - sb->size];
	sb->stack[size - sb->size] = sb->stack[size - sb->size + 1];
	sb->stack[size - sb->size + 1] = temp;
	write(1, "ss\n", 3);
	return ;
}
