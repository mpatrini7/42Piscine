/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:36:44 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/16 11:56:19 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	if ((nb % 2) == 0)
		return (0);
	while (i < (nb / 2))
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	a;

	if (nb == 2147483647)
		return (2147483647);
	if (nb <= 2)
		return (2);
	a = ft_is_prime(nb);
	if (a == 1)
		return (nb);
	else
		nb = ft_find_next_prime(nb + 1);
	return (nb);
}
