/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:57:50 by mpatrini          #+#    #+#             */
/*   Updated: 2021/11/27 12:57:54 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, int y, int o, int v)
{
	if ((o == -1 && v == -1) || (o == x && v == y))
	{
		ft_putchar('o');
	}
	else if ((v == -1 && o == x) || (v == y && o == -1))
	{
		ft_putchar('o');
	}
	else if (v == -1 || v == y)
	{
		ft_putchar('-');
	}
	else if (o == -1 || o == x)
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	o;
	int	v;

	v = -1;
	if (x > 0)
		x *= -1;
	if (y > 0)
		y *= -1;
	while (v >= y)
	{
		o = -1;
		while (o >= x)
		{
			ft_print(x, y, o, v);
			o--;
		}
		if (x != 0)
		{
			write(1, "\n", 1);
		}
		v--;
	}
}
