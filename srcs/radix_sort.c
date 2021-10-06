/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:42:27 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 17:12:20 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_lenght(int *arr, int size)
{
	int	i;
	int	res;
	int	temp;

	res = -2147483648;
	i = 0;
	while (i < size)
	{
		temp = arr[i];
		if (temp < 0)
			temp *= -1;
		if (temp > res)
			res = temp;
		i++;
	}
	i = 1;
	while (res / i >= 10)
		i *= 10;
	return (i);
}

int	*intarr_copy(int *arr, int size)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}

void	extract_nums(int *temp, int *res, int i, int size)
{
	int	t;
	int	j;
	int	y;

	y = 0;
	j = -9;
	while (j != 10)
	{
		t = 0;
		while (t < size)
		{
			if ((temp[t] / i) % 10 == j)
			{
				res[y] = temp[t];
				y++;
			}
			t++;
		}
		j++;
	}
	return ;
}

int	*radix_sort(t_stack arr, int max_lenght)
{
	int	*res;
	int	*temp;
	int	i;

	res = intarr_copy(arr.stack, arr.size);
	i = 1;
	while (i <= max_lenght)
	{
		temp = res;
		res = malloc(sizeof(int) * arr.size);
		extract_nums(temp, res, i, arr.size);
		free(temp);
		i *= 10;
	}
	return (res);
}
