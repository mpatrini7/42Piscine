/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:28:43 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/12 22:28:55 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "functions.h"

char	**fill_tab(char *file, char **tab)
{
	int		i;
	int		j;
	int		fd;
	int		n;
	char	buffer;

	i = 0;
	fd = open(file, O_RDONLY);
	n = read(fd, &buffer, SIZE_1B);
	while (n > 0)
	{
		j = 0;
		while (n > 0 && buffer != '\n')
		{
			tab[i][j] = buffer;
			n = read(fd, &buffer, SIZE_1B);
			j++;
		}
		tab[i][j] = '\0';
		i++;
		n = read(fd, &buffer, SIZE_1B);
	}
	return (tab);
}
