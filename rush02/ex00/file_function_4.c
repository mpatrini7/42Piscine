/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:29:00 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/12 22:29:03 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "functions.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	stampa_num(t_nodo *succ, int n, int ex)
{
	if (succ != 0)
	{
		if (succ->valore == n && succ->decine == ex)
			ft_putstr(succ -> nome);
		else
			stampa_num(succ->next, n, ex);
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
