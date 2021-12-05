/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:45:17 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/05 16:45:19 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sudoku_line(int *game, int *pos, int size);
int	ft_sudoku(int *game, int *pos, int size);

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

void	ft_complete(int *game, int *pos, int size)
{	
	zer = ft_calc_zer(game, size);
	if (zer != 0)
	{
		ft_sudoku(game, pos, size);
		ft_sudoku_line(game, pos, size);
		ft_sudoku_row(game, pos, size);
		//ft_complete(game, pos, size);
		return ;
	}
	else if (zer == 0)
		return ;
}
