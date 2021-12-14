/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lucifer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:13:21 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 22:08:57 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include <stdio.h>
#include "functions.h"

int	need_for_approval(char **table, int row, int col)
{
	if (approve_number(table[0]) != row - 1)
		return (0);
	rev_line(table[0], lenstr(table[0]));
	if (approve_legend(table[0]) == 0)
		return (0);
	if (approve_char(table, table[0], row, col) == 0)
		return (0);
	return (1);
}

int	approve_number(char *line)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (line[i + 3] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		num = num * 10 + (line[i] - 48);
		i++;
	}
	return (num);
}

int	approve_legend(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] < 32 || line[i] > 126)
			return (0);
		++i;
	}
	if (line[0] == line[1] || line[1] == line[2] || line[0] == line[2])
		return (0);
	return (1);
}

int	approve_char(char **table, char *legend, int row, int col)
{
	int	i;
	int	j;

	i = 1;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (table[i][j] != legend[1] && table[i][j] != legend[2])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
