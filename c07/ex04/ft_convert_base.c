/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:12:15 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/15 21:50:34 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_valid_base(char *str);
int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);

void	ft_rev_int_tab(char *tab, int size, int sign)
{
	int		i;
	int		s;
	char	temp;

	if (sign == -1)
		i = 1;
	else
		i = 0;
	s = size - 1;
	while (i < s)
	{
		temp = tab[i];
		tab[i] = tab[s];
		tab[s] = temp;
		i++;
		s--;
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_putnbr_base_rec(int nbr, char *base, int i, char *final)
{
	int	mult;

	mult = ft_strlen(base);
	i += 1;
	if (nbr == -2147483648)
	{
		final[i] = '-';
		final[i + 1] = (base[-(nbr % mult)]);
		i += 1;
		ft_putnbr_base_rec(-(nbr / mult), base, i, final);
		return ;
	}
	if (nbr < 0)
	{
		final[i] = '-';
		ft_putnbr_base_rec(-nbr, base, i, final);
		return ;
	}
	if (nbr > mult -1)
		ft_putnbr_base_rec(nbr / mult, base, i, final);
	final[i] = (base[(nbr % mult)]);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*final;
	int		i;
	int		size;
	int		ma;

	ma = 300;
	final = (char *)malloc(ma * sizeof(char));
	if (!final)
		return (NULL);
	if (ft_valid_base(base_to) == 0)
		return (NULL);
	if (ft_valid_base(base_from) == 0)
		return (NULL);
	i = -1;
	ft_putnbr_base_rec(ft_atoi_base(nbr, base_from), base_to, i, final);
	size = ft_strlen(final);
	if (final[0] == 45)
		ft_rev_int_tab(final, size, -1);
	else
		ft_rev_int_tab(final, size, 1);
	return (final);
}
