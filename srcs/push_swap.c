/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:10:40 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 17:24:59 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_stack *a, t_stack *b, int size, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (a->stack[size - a->size + j] != sorted[i]
			&& a->stack[size - j - 1] != sorted[i])
			j++;
		if (a->stack[size - a->size + j] == sorted[i])
			rotate_n(a, size, j, 'a');
		else if (a->stack[size - j - 1] == sorted[i])
			rev_rotate_n(a, size, j + 1, 'a');
		push_b(a, b, size);
		i++;
	}
	i = 0;
	while (i < size)
	{
		push_a(a, b, size);
		i++;
	}
}

void	free_all(t_stack *temp, int *sorted)
{
	if (temp)
	{
		free(temp->stack);
		free((temp + 1)->stack);
		free(temp);
	}
	if (sorted)
		free(sorted);
	return ;
}

int	clean_exit(t_stack *temp, int key)
{
	free_all(temp, 0);
	if (key == 1)
		write(1, "Error\n", 6);
	return (-1);
}

int	main(int ac, char **av)
{
	t_stack	*t;
	int		*sorted;

	if (av_check(av, ac) != 0 || ac == 1)
		return (0);
	t = initialize(ac, av);
	if (t == NULL)
		return (clean_exit(t, 1));
	if (doubles_check((&(t[0]))->stack, ac - 1) == -1)
		return (clean_exit(t, 0));
	if (stack_check(t[0], ac - 1) == 0)
		return (0);
	sorted = radix_sort(t[0], max_lenght((&(t[0]))->stack, (&(t[0]))->size));
	if (ac <= 6)
		under_5(&(t[0]), &(t[1]), ac - 1);
	else if (ac <= 100)
		insert_sort(&(t[0]), &(t[1]), ac - 1, sorted);
	else
	{
		re_arrange(sorted, (&(t[0]))->stack, ac - 1);
		binary_sort(&(t[0]), &(t[1]), ac - 1);
	}
	free_all(t, sorted);
	return (0);
}	
