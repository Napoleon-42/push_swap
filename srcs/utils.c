/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:10:37 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 17:27:21 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_intarr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 1);
		i++;
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

t_stack	*initialize(int ac, char **av)
{
	t_stack	*res;
	int		i;
	long	test;

	res = malloc(sizeof (t_stack) * 2);
	if (res == NULL)
		return (NULL);
	res[0].size = ac - 1;
	res[0].stack = malloc(sizeof (int) * (ac - 1));
	res[1].size = 0;
	res[1].stack = malloc(sizeof (int) * (ac - 1));
	i = 0;
	while (i < (ac - 1))
	{
		test = ft_atol(av[i + 1]);
		if (test < -2147483648 || test > 2147483647)
			return (NULL);
		(res[0].stack)[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (res);
}

int	stack_check(t_stack a, int size)
{
	int	i;

	i = size - a.size;
	while (i < size - 1)
	{
		if (a.stack[i] > a.stack[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

void	execute_utils(t_stack *data, int size, char *str, int *i)
{
	if (str[*i] == 's')
	{
		swap_ab(&(data[0]), &(data[1]), size);
		*i = *i + 2;
		return ;
	}
	if (str[*i] == 'r')
	{
		if (str[*i + 2] == 'a' || str[*i + 2] == 'b' || str[*i + 2] == 'r')
		{
			if (str[*i + 2] == 'a')
				rev_rotate_a(&(data[0]), size);
			else if (str[*i + 2] == 'b')
				rev_rotate_b(&(data[1]), size);
			else
				rev_rotate_ab(&(data[0]), &(data[1]), size);
			*i = *i + 3;
		}
		else
		{
			rotate_ab(&(data[0]), &(data[1]), size);
			*i = *i + 2;
		}
	}
	return ;
}

void	execute(t_stack *a, t_stack *b, int size, char *commands)
{
	int	i;

	i = 0;
	while (commands[i] != '\0')
	{
		if (commands[i] == '\n')
			i++;
		if (commands[i + 1] != 's' && commands[i + 1] != 'r')
		{
			if (commands[i] == 'p')
				execute_utils_push(a, size, commands, i);
			if (commands[i] == 's' && commands[i + 1] == 'a')
				swap_a(a, size);
			if (commands[i] == 's' && commands[i + 1] == 'b')
				swap_b(b, size);
			if (commands[i] == 'r' && commands[i + 1] == 'a')
				rotate_a(a, size);
			if (commands[i] == 'r' && commands[i + 1] == 'b')
				rotate_b(b, size);
			i = i + 2;
		}
		else
			execute_utils(a, size, commands, &i);
	}
	return ;
}

/*
void	print(t_stack a, t_stack b, int size)
{
	int y;
	int size_max;
	
	size_max = a.size;
	if (b.size > size_max)
		size_max = b.size;
	y = size - size_max;
	if (size_max == a.size)
		while (y < size)
		{
			ft_putnbr_fd(a.stack[y], 1);
			write(1, "\t\t\t\t", 4);
			if (y >= (size - b.size))
				ft_putnbr_fd(b.stack[y], 1);
			write(1, "\n", 1);
			y++;
		}
	else
		while (y < size)
		{
			if (y >= (size - a.size))
				ft_putnbr_fd(a.stack[y], 1);
			write(1, "\t\t\t\t", 4);
			ft_putnbr_fd(b.stack[y], 1);
			write(1, "\n", 1);
			y++;
		}
	write(1, "_\t\t\t\t_\n", 7);
	write(1, "a\t\t\t\tb\n", 7);
	ft_putnbr_fd(a.size, 1);
	write(1, "\t\t\t\t", 4);
	ft_putnbr_fd(b.size, 1);
	write(1, "\t = sizes\n", 10);
	write(1, "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n", 34);
	return ;
}
*/
