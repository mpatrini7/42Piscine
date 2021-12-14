/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctor_who.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:13:05 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 22:31:02 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"
#include <stdio.h>
#include "functions.h"

char	*tastiera(char *input)
{
	int		i;
	char	c;

	i = 0;
	while (read(0, &c, 1) && c != '\n')
	{
		input[i] = c;
		i++;
	}
	input[i] = '\0';
	return (input);
}

char	**generate_file_tab(char *file, int *row, int *col)
{
	int		i;
	char	**tab;
	int		first_row;

	first_row = 0;
	first_row = get_rows_cols(file, row, col);
	if (*col <= 0)
		return (0);
	i = 1;
	tab = (char **) malloc ((*row) * sizeof(char *));
	if (!tab)
		return (0);
	tab[0] = (char *) malloc ((first_row + 1) * sizeof(char));
	while (i < (*row))
	{
		tab[i] = (char *) malloc ((*col) * sizeof(char));
		if (!tab[i])
			return (0);
		i++;
	}
	if (fill_tab(file, tab, *col, first_row) == 0)
		return (tab);
	if (need_for_approval(tab, *row, *col) == 0)
		return (0);
	return (tab);
}

void	fill_tab2(int *mix, char buffer, int first_row, char **tab)
{
	while (mix[3] > 0 && buffer != '\n')
	{
		if (mix[0] == 0 && mix[1] == first_row)
		{
			tab[mix[0]][mix[1]] = '\0';
			break ;
		}
		else if (mix[0] == 0 && mix[1] < first_row)
			tab[mix[0]][mix[1]] = buffer;
		else
			tab[mix[0]][mix[1]] = buffer;
		mix[3] = read(mix[2], &buffer, 1);
		mix[1]++;
	}
}

int	fill_tab(char *file, char **tab, int col, int first_row)
{
	int		mix[4];
	char	buffer;

	mix[0] = 0;
	mix[2] = open(file, O_RDONLY);
	mix[3] = read(mix[2], &buffer, 1);
	while (mix[3] > 0)
	{
		mix[1] = 0;
		fill_tab2(mix, buffer, first_row, tab);
		tab[mix[0]][mix[1]] = '\0';
		if (mix[0] > 1 && (mix[1] < col || mix[1] > col))
			return (0);
		else if (mix[0] == 0 && mix[1] < first_row)
			return (0);
		mix[0]++;
		mix[3] = read(mix[2], &buffer, 1);
	}
	return (1);
}
