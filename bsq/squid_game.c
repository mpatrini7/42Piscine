/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squid_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:07:30 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 21:30:00 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include "functions.h"

int	obstacle_found_row(int **arr, int col, int row, int pos[3])
{
	while (pos[0] <= row)
	{
		if (arr[row][col] == 1)
			return (1);
		row--;
	}
	return (0);
}

int	square_check2(int **arr, int pos[3], int s_pos[2])
{
	int	row;
	int	col;

	if (arr[s_pos[0]][s_pos[1]] == 0)
	{
		col = s_pos[1];
		row = s_pos[0];
		if (obstacle_found_col(arr, col, row, pos))
			return (0);
		if (obstacle_found_row(arr, col, row, pos))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	square_check(int **arr, int pos[3], int size[2], int temp_pos[3])
{
	int	max;
	int	s_pos[2];

	s_pos[0] = pos[0];
	s_pos[1] = pos[1];
	max = 1;
	while (s_pos[0] < size[0] && s_pos[1] < (size[1] + 1))
	{	
		if (arr[s_pos[0]][s_pos[1]] == 1)
			break ;
		s_pos[0]++;
		s_pos[1]++;
		pos[2] = max;
		if (square_check2(arr, pos, s_pos) == 0)
			break ;
		max++;
	}
	temp_pos[0] = pos[0];
	temp_pos[1] = pos[1];
	temp_pos[2] = pos[2];
}

void	the_square_game2(int final_pos[3], int max[2], int temp_pos[3])
{
	max[0] = temp_pos[2];
	final_pos[0] = temp_pos[0];
	final_pos[1] = temp_pos[1];
	final_pos[2] = temp_pos[2];
}

void	the_square_game(int **arr, int size[2], int final_pos[3])
{
	int	temp_pos[3];
	int	pos[3];
	int	max[2];

	max[1] = -1;
	while (++max[1] < 3)
	{
		temp_pos[max[1]] = 0;
		pos[max[1]] = -1;
	}
	size[0] -= 1;
	size[1] -= 1;
	max[0] = 0;
	while (++pos[0] < size[0])
	{	
		pos[1] = -1;
		while (++pos[1] < size[1])
		{
			square_check(arr, pos, size, temp_pos);
			if (max[0] < temp_pos[2])
				the_square_game2(final_pos, max, temp_pos);
		}
	}
}
