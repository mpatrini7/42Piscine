/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:12:54 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 22:31:25 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include "functions.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		main2();
	else
	{
		while (i < argc)
		{
			see_map(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

void	main2(void)
{
	char	a[1000];

	see_map(tastiera(a));
}

void	error_map(void)
{
	write(err, "Map Error\n", 11);
}

void	see_map(char *file)
{
	char	**tab;
	int		**vins;
	int		square[3];
	int		cord[2];

	cord[0] = 0;
	cord[1] = 0;
	tab = generate_file_tab(file, &cord[0], &cord[1]);
	if (!tab)
	{
		error_map();
		return ;
	}
	vins = make_matrix(cord[0], cord[1]);
	if (vins == 0)
		return ;
	//rev_line(tab[0], lenstr(tab[0]));
	cord[0] = cord[0];
	cord[1] = cord[1];
	convert_arr(tab, vins, *tab, cord);
	the_square_game(vins, cord, square);
	print_square(tab, square, tab[0], cord);
	return ;
}

int	**make_matrix(int row, int col)
{
	int	**ret;
	int	i;
	int	j;

	i = 0;
	ret = (int **) malloc (row * sizeof(int *));
	if (!ret)
		return (0);
	while (i <= row - 1)
	{
		j = 0;
		ret[i] = (int *) malloc (col * sizeof(int));
		while (j < col)
		{
			ret[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ret);
}
