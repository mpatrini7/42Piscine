/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:43:20 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/07 22:43:23 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid_base(char *str)
{
	char	*c;
	int		i;
	int		o;

	c = str;
	i = 0;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*c)
	{
		if (*c == 32 || *c == '\t' || *c == '\v' || *c == '\f'
			|| *c == '\r' || *c == '\n' || *c == '+' || *c == '-')
			return (0);
		c++;
	}
	while (i < c - str)
	{
		o = i + 1;
		while (o < c - str)
			if (str[i] == str[o++])
				return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base_rec(int nbr, char *base, int mult)
{
	if (nbr == -2147483648)
	{
		ft_putnbr_base_rec(nbr / mult, base, mult);
		write(1, &(base[-(nbr % mult)]), 1);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base_rec(-nbr, base, mult);
		return ;
	}
	if (nbr > mult -1)
		ft_putnbr_base_rec(nbr / mult, base, mult);
	write(1, &(base[(nbr % mult)]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	m;

	if (ft_valid_base(base) == 0)
		return ;
	m = ft_strlen(base);
	ft_putnbr_base_rec(nbr, base, m);
}
