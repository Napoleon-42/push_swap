/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:26:29 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 17:08:20 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	av_check(char **strs, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (1);
	while (strs[i])
	{
		j = 0;
		if (strs[i][j] == '-')
			j++;
		if (strs[i][j] == '\0')
			return (error_exit());
		while (strs[i][j] != '\0')
		{
			if (ft_isdigit((int)strs[i][j]) == 0)
				return (error_exit());
			j++;
		}
		i++;
	}
	return (0);
}

int	doubles_check(int *a, int size)
{
	int	i;
	int	y;
	int	temp;

	i = 0;
	temp = a[0];
	while (i < size)
	{
		y = i + 1;
		temp = a[i];
		while (y < size)
		{
			if (temp == a[y])
				return (error_exit());
			y++;
		}
		i++;
	}
	return (0);
}
