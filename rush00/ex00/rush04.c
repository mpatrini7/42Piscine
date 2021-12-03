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
	if ((o == -1 && v == -1) || (o == x && v == y && v != -1 && x != -1))
	{
		ft_putchar('A');
	}
	else if ((v == -1 && o == x) || (v == y && o == -1))
	{
		ft_putchar('C');
	}
	else if (v == -1 || v == y || o == x || o == -1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	ft_print_rev(int x, int y, int o, int v)
{
	if ((o == -1 && v == -1) || (o == x && v == y && v != -1 && x != -1))
	{
		ft_putchar('C');
	}
	else if ((v == -1 && o == x) || (v == y && o == -1))
	{
		ft_putchar('A');
	}
	else if (v == -1 || v == y || o == x || o == -1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	ft_posneg(int x, int y)
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

void	ft_mixed(int x, int y)
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
			ft_print_rev(x, y, o, v);
			o--;
		}
		if (x != 0)
		{
			write(1, "\n", 1);
		}
		v--;
	}
}

void	rush(int x, int y)
{
	if ((x > 0 && y > 0) || (x < 0 && y < 0))
	{
		ft_posneg(x, y);
	}
	else
	{
		ft_mixed(x, y);
	}
}
