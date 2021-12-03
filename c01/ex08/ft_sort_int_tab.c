/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:37:34 by mpatrini          #+#    #+#             */
/*   Updated: 2021/11/29 12:37:36 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	i2;
	int	swap;

	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			if (tab[i] < tab[i2])
			{
				swap = tab[i];
				tab[i] = tab[i2];
				tab[i2] = swap;
			}
			i2++;
		}
		i++;
	}
}
