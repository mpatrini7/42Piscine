/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:36:17 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/02 22:36:19 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (dest[k] != '\0')
		k++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[k] = src[i];
			i++;
			k++;
		}
		dest[k] = '\0';
	}
	return (k);
