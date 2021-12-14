/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stanger_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:29:21 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 23:33:35 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include "functions.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	lenstr(char*str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_rows_cols(char *file, int *rows, int *cols)
{
	int		fd;
	int		i;
	char	buffer;
	int		first_row;

	fd = open(file, O_RDONLY);
	i = read(fd, &buffer, 1);
	while (i > 0)
	{
		(*cols) = 0;
		while (buffer != '\n')
		{
			i = read(fd, &buffer, 1);
			(*cols)++;
		}
		if ((*rows) == 0)
			first_row = (*cols);
		(*rows)++;
		i = read(fd, &buffer, 1);
	}
	return (first_row);
}
