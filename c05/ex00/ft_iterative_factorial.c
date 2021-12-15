/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:36:16 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/15 11:25:08 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	a = 1;
	while (i < nb + 1)
	{
		a = a * i;
		i++;
	}
	return (a);
}
