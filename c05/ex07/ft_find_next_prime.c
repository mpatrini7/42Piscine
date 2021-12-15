/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:36:44 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/15 22:04:48 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	n;
	int	c;

	c = nb;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	i = 0;
	n = 0;
	while (n < c)
	{
		n = i * i;
		i++;
	}
	i -= 1;
	if (i * i == nb)
		return (i);
	return (i + 1);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sq;

	if (nb < 2)
		return (0);
	else if (nb < 4)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 2;
	sq = ft_sqrt(nb);
	while ((i <= sq) && (nb % i != 0))
		i++;
	if (i > sq)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
}
