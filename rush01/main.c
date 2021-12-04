/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:34:56 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/04 11:34:57 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_static(int *game, int *pos, int size);

int	ft_dimension(char *av)
{
	int	m;
	int	i;

	i = 0;
	m = 0;
	while (av[i])
	{
		if (av[i] >= 49 && av[i] <= 57)
			m++;
		i++;
	}
	return (m);
}

int	*ft_rtrv(char **av, int size)
{
	int	i;
	int	in;
	int	*pos;
	int sti;

	i = 0;
	in = 0;
	pos = (int *) malloc(sizeof(int) * size);
	while (av[1][i])
	{	
		if (av[1][i] >= 49 && av[1][i] <= ((size / 4) + 48))
		{
			pos[in] = av[1][i] - 48;
			in++;
			i++;
		}
		else if (av[1][i] == 48)
			return (0);
		else if (av[1][i] - 48 > size / 4)
			return (0);
		else
			i++;
	}
	return (pos);
}

void	ft_print_game(int *game, int size)
{
	int	i;
	int	print;

	i = 0;
	print = size / 4;
	while (game[i])
	{
		if (i % print == 0)
			write(1, "\n", 1);
		write(1, game + i, 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_game(int *pos, int size)
{
	int	*game;

	game = (int *) malloc(sizeof(int) * size);
	ft_static(game, pos, size);
	//ft_complete(game, pos, size);
	ft_print_game(game, size);
}

int	main(int ac, char **av)
{
	int	*pos;
	int	size;

	if (ac == 2)
	{
		size = ft_dimension(av[1]);
		if (size % 4 != 0)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		pos = ft_rtrv(av, size);
		if (pos == NULL)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		ft_game (&*pos, size);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}
