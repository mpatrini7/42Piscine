/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:12:15 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/10 16:12:18 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_valid_base(char *str);
int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);

void	ft_rev_int_tab(char *tab, int size, int sign)
{
	int		i;
	int		s;
	char	temp;

	if(sign == -1)
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

void	ft_putnbr_base_rec(int nbr, char *base, int mult, int i, char *final)
{	
	i += 1;
	if (nbr == -2147483648)
	{
		ft_putnbr_base_rec(nbr / mult, base, mult, i, final);
		final[i] = (base[-(nbr % mult)]);
		return ;
	}
	if (nbr < 0)
	{
		final[i] = '-';
		ft_putnbr_base_rec(-nbr, base, mult, i, final);
		return ;
	}
	if (nbr > mult -1)
		ft_putnbr_base_rec(nbr / mult, base, mult, i, final);
	final[i] = (base[(nbr % mult)]);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *final;
	int i;
	int	size;
	int ma;
	ma = 40;
	final = (char*)malloc(ma * sizeof(char));

	if (ft_valid_base(base_to) == 0)
		return(0);
	i = -1;
	ft_putnbr_base_rec(ft_atoi_base(nbr, base_from), base_to, ft_strlen(base_to), i, final);
	size = ft_strlen(final);
	if(final[0] == 45)
		ft_rev_int_tab(final, size, -1);
	else
		ft_rev_int_tab(final, size, 1);

	return(final);
}

int		main(void)
{
	printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("result : $%s$\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("result : $%s$\n", ft_convert_base("---+--0001023a", "0123456789", "0123456789"));
	printf("result : $%s$\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
}