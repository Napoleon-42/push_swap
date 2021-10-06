/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:34:24 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/27 16:36:33 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under_3(t_stack *sa, int size)
{
	if (stack_check(*sa, size) == 0 || sa->size == 1)
		return ;
	if (sa->size == 2)
		swap_a(sa, size);
	if (sa->stack[size - 3] > sa->stack[size - 2] && sa->size != 2)
	{
		if (!(sa->stack[size - 2] > sa->stack[size - 1]))
		{
			if (sa->stack[size - 3] > sa->stack[size - 1])
				rotate_a(sa, size);
			else
				swap_a(sa, size);
		}
		else
			execute(sa, NULL, size, "\nsa\nrra");
	}
	else if (sa->size != 2)
	{
		if (sa->stack[size - 3] > sa->stack[size - 1])
			rev_rotate_a(sa, size);
		else
			execute(sa, NULL, size, "\nsa\nra");
	}
	return ;
}

void	under_2(t_stack *sa)
{
	if (sa->stack[0] > sa->stack[1])
		swap_a(sa, 2);
	return ;
}

void	under_4(t_stack *sa, t_stack *sb)
{
	execute(sa, sb, 4, "pb");
	under_3(sa, 4);
	if (sb->stack[3] < sa->stack[1])
		push_a(sa, sb, 4);
	else if (sb->stack[3] < sa->stack[2])
	{
		push_a(sa, sb, 4);
		swap_a(sa, 4);
	}
	else if (sb->stack[3] > sa->stack[3])
	{
		push_a(sa, sb, 4);
		rotate_a(sa, 4);
	}
	else if (sb->stack[3] > sa->stack[2] && sb->stack[3] < sa->stack[3])
		execute(sa, sb, 4, "rra\npa\nra\nra");
	return ;
}

void	under_5_utils3(t_stack *sa, t_stack *sb)
{
	execute(sa, sb, 5, "rra\npa\nrra\nrra\npa");
	if (sa->stack[0] > sa->stack[1])
		swap_a(sa, 5);
}

void	under_5(t_stack *sa, t_stack *sb, int size)
{
	if (stack_check(*sa, size) == 0)
		return ;
	if (size == 2)
		return (under_2(sa));
	if (size == 3)
		return (under_3(sa, size));
	if (size == 4)
		return (under_4(sa, sb));
	execute(sa, sb, size, "pb\npb");
	rev_under_2(sb);
	under_3(sa, size);
	if (!(sb->stack[3] > sa->stack[3] && sb->stack[3] < sa->stack[4]))
		under_5_utils(sa, sb);
	else
	{
		if ((sa->stack[3] > sb->stack[4] && sa->stack[3] > sb->stack[3]) || (
				sa->stack[3] < sb->stack[4] && sa->stack[3] < sb->stack[4]))
			execute(sa, sb, 5, "rra\npa\npa\nra\nra\nra");
		else
			under_5_utils3(sa, sb);
	}
	return ;
}
