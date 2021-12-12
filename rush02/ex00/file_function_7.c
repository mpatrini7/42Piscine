/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:29:30 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/12 22:29:33 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "functions.h"

void	libera_tab(char **tab, int num_righe)
{
	int	i;

	i = 0;
	while (i < num_righe)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	libera_diz(t_nodo *succ)
{
	if (succ != 0)
	{
		libera_diz(succ->next);
		free(succ);
	}
}

int	my_atoi2_2(int n)
{
	if (n > 99)
		n = 1;
	return (n);
}
