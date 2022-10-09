/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:01:09 by mpatrini          #+#    #+#             */
/*   Updated: 2021/11/29 16:01:16 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_print(int *tab, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i])
			return (0);
		i++;
	}
	return (1);
}


void	ft_print_combn2(int *tab, int n)
{
	int	i;

	i = 0;
	if (ft_is_print(tab, n) == 0)
		return ;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[n];

	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	while (tab[0] <= (10 - n) && n >= 1 && n < 10)
	{
		ft_print_combn2(tab, n);
		tab[n - 1]++;
		i = n - 1;
		while(i > 0 && n > 1)
		{
			if (tab[i] > 9)
			{
				tab[i] = 0;
				tab[i - 1]++;
			}
			i--;
		}
	}
}
