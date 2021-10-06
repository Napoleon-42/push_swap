/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_5_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:36:55 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/27 16:38:01 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_under_2(t_stack *b)
{
	if (b->stack[4] > b->stack[3])
		swap_b(b, 5);
	return ;
}

void	under_5_utils2(t_stack *sa, t_stack *sb)
{
	rotate_a(sa, 5);
	push_a(sa, sb, 5);
	if (sa->stack[0] > sa->stack[1])
		swap_a(sa, 5);
	return ;
}

void	under_5_utils(t_stack *sa, t_stack *sb)
{
	if (sb->stack[3] < sa->stack[2])
		execute(sa, sb, 5, "pa\npa");
	else if (sb->stack[3] > sa->stack[2] && sb->stack[3] < sa->stack[3])
	{
		execute(sa, sb, 5, "pa\nsa\npa");
		if (sb->stack[4] > sa->stack[1])
			swap_a(sa, 5);
	}
	else if (sb->stack[3] > sa->stack[4] && sb->stack[4] < sa->stack[3])
	{
		execute(sa, sb, 5, "pa\nra\npa");
		if (sa->stack[0] > sa->stack[1])
			swap_a(sa, 5);
	}
	else
	{
		if (sb->stack[4] < sa->stack[4])
			execute(sa, sb, 5, "pa\nrra\npa\nra\nra\nra");
		else
			execute(sa, sb, 5, "pa\npa\nra\nra");
	}
	return ;
}
