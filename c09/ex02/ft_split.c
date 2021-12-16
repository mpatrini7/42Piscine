/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:23:19 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/15 18:28:34 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			while (str[i] != '\0')
			{
				if (ft_is_charset(str[i], charset) == 1)
					break ;
				i++;
				len++;
			}
			return (len);
		}
		else
			i++;
	}
	return (0);
}

int	ft_add_str(char *str, char *charset, char *final)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			while (str[i] != '\0')
			{
				if (ft_is_charset(str[i], charset) == 1)
					break ;
				final[in] = str[i];
				in++;
				i++;
			}
			final[in] = '\0';
			return (i);
		}
		else
			i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 0)
		{
			count++;
			while (str[i] != '\0')
			{
				if (ft_is_charset(str[i], charset) == 1)
					break ;
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**final;
	int		row;
	int		len;
	int		offset;

	offset = 0;
	count = ft_count(str, charset);
	final = (char **) malloc (sizeof(char *) * count + 1);
	final[count] = 0;
	row = 0;
	while (row < count)
	{
		len = ft_strlen(str, charset);
		final[row] = (char *) malloc (sizeof(char) * len + 1);
		offset = ft_add_str(str, charset, final[row]);
		str += offset;
		row++;
	}
	return (final);
}
