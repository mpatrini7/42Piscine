/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:26:55 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 20:16:09 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0
	count = 0;
	while(str[i])
	{
		if(str[i] == '\0')
			return (count + 1)
		else if (str[i] == charset && str[i-1] != charset)
			count++;
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{

}