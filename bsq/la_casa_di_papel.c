/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   la_casa_di_papel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:19:41 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 21:30:05 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include "functions.h"

int	obstacle_found_col(int **arr, int col, int row, int pos[3])
{
	while (pos[1] <= col)
	{
		if (arr[row][col] == 1)
			return (1);
		col--;
	}
	return (0);
}

void	convert_arr(char **map, int **vins, char *var, int *cord)
{
	int	i;
	int	in;
	int	a;

	i = 1;
	a = 0;
	while (i < cord[0])
	{
		in = 0;
		while (in < cord[1])
		{
			if (map[i][in] == var[2])
				vins[a][in] = 0;
			else
				vins[a][in] = 1;
			in++;
		}
		a++;
		i++;
	}
}

void	print_square(char **map, int *square, char *var, int *cord)
{
	int	i;
	int	in;

	i = 1;
	while (i <= cord[0])
	{
		if (i < square[0] + 1 || i > (square[0] + square[2]))
		{
			ft_putstr(map[i]);
		}
		else
		{
			in = 0;
			while (in <= cord[1])
			{
				if ((in >= square[1]) && (in <= (square[1] + square[2] - 1)))
					ft_putchar(var[0]);
				else
					ft_putchar(map[i][in]);
				in++;
			}
		}
		i++;
		write(1, "\n", 1);
	}
}

void	rev_line(char *tab, int size)
{
	int	first;
	int	last;
	int	diff_index;

	first = 0;
	last = size - 1;
	diff_index = last - first;
	if (size == 0)
	{
		return ;
	}
	while (diff_index >= 1)
	{
		ft_swap(tab + first, tab + last);
		first++;
		last--;
		diff_index = last - first;
	}
}
