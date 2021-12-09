/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:42:10 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 21:07:59 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	c;

	c = nb;
	if(nb < 0)
		return (0);
	else if(nb <= 1)
		return (1);
	i = 0;
	n = 0;
	while (n < c)
	{
		n = i * i;
		i++;
	}
	i -= 1;
	if(i * i == nb)
		return(i);
	return(0);
}
