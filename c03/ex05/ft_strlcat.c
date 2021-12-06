/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:36:17 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/06 14:17:23 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;
	unsigned int	c;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	offset = d_len;
	c = 0;
	if (size == 0)
		return (s_len);
	while (src[c] != '\0' && offset + c < (size - 1))
	{
		dest[offset + c] = src[c];
		c++;
	}
	if (c < size)
		dest[offset + c] = '\0';
	if (d_len > size)
		return (s_len + size);
	return (d_len + s_len);
}
