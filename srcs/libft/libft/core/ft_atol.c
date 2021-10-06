/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:07:08 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/06 17:37:26 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long	res;
	int		i;
	short	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		if (res > 2147483647 || res < -2147483648)
			return (res * sign);
		i++;
	}
	return (res * sign);
}
