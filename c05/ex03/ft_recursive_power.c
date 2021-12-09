/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:32:55 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 20:39:17 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power2(int nb, int power, int res)
{
	if (power == 0)
		return (res);
	else
	{
		res *= nb;
		power--;
	}
	ft_recursive_power2(nb, power, res);
}

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_power2(nb, power, res));
}