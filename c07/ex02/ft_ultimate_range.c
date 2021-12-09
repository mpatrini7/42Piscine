/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:33:01 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 11:33:03 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*r;
	int	i;

	*range = NULL;
	if (min >= max)
		return (0);
	size = max - min;
	r = (int *)malloc(size * sizeof(int));
	if (r == NULL)
		return (-1);
	*range = r;
	i = 0;
	while (i < size)
	{
		r[i] = min;
		min++;
		i++;
	}
	return (size);
}
