/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:42:30 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/05 20:42:34 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sudoku_x(int *game, int *pos, int size, int num)
{
	int	i;
	int	count;
	int	in;

	i = 0;
	while (i < size)
	{
		if (i % 4 == 0)
		{
			in = 0;
			count = 0;
			while (in < (size / 4) && count == 0)
			{
				if (game[i + in] == num)
					count = 1;
				in++;
			}
			if (count == 0)
				return (i);
		}
		i++;
	}
	return (0);
}

int	ft_sudoku_y(int *game, int *pos, int size, int num)
{
	int	i;
	int	count;
	int	in;

	i = 0;
	while (i < (size / 4))
	{
		in = 0;
		count = 0;
		while (in < size && count == 0)
		{
			if (game[i + in] == num)
				count = 1;
			in += (size / 4);
		}
		if (count == 0)
			return (i);
		i++;
	}
	return (0);
}

void	ft_sudoku(int *game, int *pos, int size)
{
	int	i;
	int	num;
	int	count;
	int	x;
	int	y;

	num = 1;
	while (num <= (size / 4))
	{
		i = 0;
		count = 0;
		while (i < size)
		{
			if (game[i] == num)
				count += 1;
			i++;
		}
		if (count == ((size / 4) - 1))
		{
			y = ft_sudoku_y(game, pos, size, num);
			x = ft_sudoku_x(game, pos, size, num);
			game[x + y] = num;
		}
		num++;
	}
}

void	ft_sudoku_line2(int *game, int *pos, int size, int k)
{
	int	i;
	int	sum;

	sum = 0;
	i = 3;
	while (i >= 0)
	{
		sum += game[k + i];
		i--;
	}
	sum = 10 - sum;
	i = 3;
	while (i >= 0)
	{
		if (game[k + i] == 0)
		{
			game[k + i] = sum;
			return ;
		}
		i--;
	}
}

void	ft_sudoku_line(int *game, int *pos, int size)
{
	int	i;
	int	count;
	int	in;

	i = 0;
	while (i < size)
	{
		if (i % 4 == 0 || i == 0)
		{
			in = 0;
			count = 0;
			while (in < (size / 4))
			{
				if (game[i + in] != 0)
					count++;
				in++;
			}
			if (count == 3)
			{
				ft_sudoku_line2(game, pos, size, i);
			}
		}
		i++;
	}
}
