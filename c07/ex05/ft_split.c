/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:23:19 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 20:23:25 by mpatrini         ###   ########.fr       */
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

int	ft_is_charset(char c, char *charset)
{
	while(1)
	{
		if(*charset = '\0')
			return(0);
		if(*charset = c)
			return(1);
		charset++;
	}
	return (0);
}

void	ft_add_string(char **final, char *start, char *charset, int size)
{
	if(ft_is_charset(start[0], charset) == 1)
	{
		start++;
		size--;
	}
	*final = (char *)malloc((size + 1) * sizeof(char));
	ft_strncpy(*final, start, size);
}

int	ft_count(char *str, char *charset)
{
	int		count;
	char	*start;
	char	*finish;

	count = 0;
	start = str;
	finish = str;
	while(1)
	{
		if(ft_is_charset(*str, charset) == 1)
			finish = str;
		if (finish - start > 1)
			count++;
		if(*str == '\0')
			break ;
		start = finish;
		str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char 	**final;
	int 	i;
	char	*start;
	char	*finish;
	int		size;
	
	final = (char **)malloc((ft_count(str, charset) + 1) * sizeof(char *));
	i = 0;
	start = str;
	finish = str;
	while(1)
	{
		if(ft_is_charset(*str, charset) == 1)
			finish = str;
		size = finish - start;
		prtinf()
		if (size > 1)
			ft_add_string(&final[i], start, charset, size);
			i++;
		if(*str == '\0')
			break ;
		start = finish;
		str++;
	}
	final[i] = 0;
	return (final);
}

int	main(/*int argc, char *argv[]*/)
{
	char	**matrix;
	int		i;
​
	i = 0;
	//matrix = ft_split(argv[1], argv[2]);
	matrix = ft_split("michael e molto bravo", " ");
	while (matrix[i] != 0)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	//printf("%s\n", argv[1]);
}
