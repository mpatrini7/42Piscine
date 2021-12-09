/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:32:53 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 11:32:55 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*r;
	int	i;

	r = NULL;
	if (min >= max)
		return (r);
	size = max - min;
	r = (int *)malloc(size * sizeof(int));
	if (r == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		r[i] = min;
		min++;
		i++;
	}
	return (r);
}
