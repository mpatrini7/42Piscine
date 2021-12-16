/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:41:00 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/16 21:24:27 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *str, int size)
{
	char	*copy;
	int		i;

	copy = 0;
	copy = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i += 1;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_str;
	int			i;
	int			len;

	stock_str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock_str == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
			len++;
		stock_str[i].size = len;
		stock_str[i].str = av[i];
		stock_str[i].copy = ft_strcpy(av[i], stock_str[i].size);
		i += 1;
	}
	stock_str[i].size = 0;
	stock_str[i].str = 0;
	stock_str[i].copy = 0;
	return (stock_str);
}
