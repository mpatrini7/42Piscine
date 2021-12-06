/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:42:06 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/05 20:42:11 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sudoku_row2(int *game, int *pos, int size, int k)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < (size / 4))
	{
		sum += game[k + (i * (size / 4))];
		i++;
	}
	sum = 10 - sum;
	i = 0;
	while (i < (size / 4))
	{
		if (game[k + (i * (size / 4))] == 0)
		{
			game[k + (i * (size / 4))] = sum;
			return ;
		}
		i++;
	}
}

void	ft_sudoku_row(int *game, int *pos, int size)
{
	int	i;
	int	count;
	int	in;

	i = 0;
	while (i < size)
	{
		if (i < size / 4)
		{	
			in = 0;
			count = 0;
			while (in < (size / 4))
			{
				if (game[i + (in * (size / 4))] != 0)
					count++;
				in++;
			}
			if (count == 3)
			{
				ft_sudoku_row2(game, pos, size, i);
			}
		}
		i++;
	}
}

int	ft_calc_zer(int *game, int size)
{
	int	i;
	int	zer;

	i = 0;
	while (i < size)
	{
		if (game[i] == 0)
			zer++;
		i++;
	}
	return (zer);
}
