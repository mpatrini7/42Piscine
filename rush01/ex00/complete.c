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

void	ft_sudoku_line(int *game, int *pos, int size);
void	ft_sudoku(int *game, int *pos, int size);
void	ft_sudoku_row2(int *game, int *pos, int size, int k);
void	ft_sudoku_row(int *game, int *pos, int size);
int		ft_calc_zer(int *game, int size);
int		ft_count(int *game, int *pos, int size);
void	ft_twotwo3(int *game, int size, int save, int sum);
void	ft_twotwo4(int *game, int size, int save, int sum);
void	ft_twotwo2(int *game, int *pos, int size, int i);
void	ft_twotwo(int *game, int *pos, int size);
void	ft_reversesudoku(int *game, int *pos, int size);

void	ft_twotwo_23(int *game, int size, int save, int sum)
{
	if ((sum == 3 && save % 4 == 0) || (sum == 5 && save % 4 == 0))
	{
		game[save + 8] = sum / 2;
		game[save + 12] = sum / 2 + 1;
	}
	else if (sum == 4 && save % 4 == 0)
	{
		game[save + 8] = 1;
		game[save + 12] = 3;
	}
	else if ((sum == 3 && save % 4 == 2) || (sum == 5 && save % 4 == 2))
	{
		game[save - 8] = sum / 2;
		game[save + 12] = sum / 2 + 1;
	}
	else if (sum == 4 && save % 4 == 2)
	{
		game[save - 8] = 1;
		game[save + 12] = 3;
	}
}

void	ft_twotwo_24(int *game, int size, int save, int sum)
{
	if (sum == 3 || sum == 5)
	{
		game[save] = sum / 2 + 1;
		game[save + 2] = sum / 2;
	}
	else if (sum == 4)
	{
		game[save] = 3;
		game[save + 2] = 1;
	}
}

void	ft_twotwo_22(int *game, int *pos, int size, int i)
{
	int	in;
	int	save;
	int	sum;

	sum = 10;
	in = 0;
	while (in < (size / 4))
	{
		sum -= game[i + in];
		if (game[i + in] > 0 && game[i + in] != (size / 4))
			save = i + in;
		in++;
	}
	if (save % 4 == 0 || save % 4 == 2)
		ft_twotwo_23(game, size, save, sum);
	else if (save % 4 == 3)
		ft_twotwo_24(game, size, save, sum);
}

void	ft_twotwo_2(int *game, int *pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i >= (size / 2) && i < (size - (size / 4)))
		{
			if (pos[i] == 2 && pos[i + (size / 4)] == 2)
			{
				if (ft_count(game, pos, size) == 2)
				{
					ft_twotwo2(game, pos, size, i);
				}
			}
		}
		i++;
	}
}

void	ft_complete(int *game, int *pos, int size)
{
	int	zer;

	zer = ft_calc_zer(game, size);
	if (zer != 0)
	{
		ft_sudoku(game, pos, size);
		ft_sudoku_line(game, pos, size);
		ft_sudoku_row(game, pos, size);
		ft_complete(game, pos, size);
		return ;
	}
	else if (zer == 0)
		return ;
}
