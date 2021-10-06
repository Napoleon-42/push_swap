/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:26:28 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/26 18:30:12 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_arrange(int *sorted, int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (arr[i] != sorted[j])
			j++;
		arr[i] = j;
		i++;
	}
	return ;
}

int	max_l_inbin(int size)
{
	int	i;

	i = 1;
	while (size / 2 != 0)
	{
		size = size / 2;
		i++;
	}
	return (i);
}

void	binary_sort(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	j;
	int	max_length;

	max_length = max_l_inbin(size);
	i = 0;
	while (i < max_length)
	{
		j = 0;
		while (b->size > 0)
			push_a(a, b, size);
		while (j < size)
		{
			if (((a->stack[size - a->size] >> i) & 1) == 1)
				rotate_a(a, size);
			else
				push_b(a, b, size);
			j++;
		}
		i++;
	}
	while (b->size > 0)
		push_a(a, b, size);
	return ;
}
