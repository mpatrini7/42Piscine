/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <mpatrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:33:14 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/14 12:50:30 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	ft_add_sep(char *sep, char *r, int a)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		r[a] = sep[i];
		a++;
		i++;
	}
	return (a);
}

char	*ft_strjoin2(char *r, char **strs, char *sep, int size)
{
	int	a;
	int	i;
	int	in;

	i = 0;
	a = 0;
	while (i < size)
	{
		in = 0;
		while (strs[i][in])
		{
			r[a] = strs[i][in];
			in++;
			a++;
		}
		a = ft_add_sep(sep, r, a);
		i++;
	}
	r[a] = '\0';
	return (r);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*r;
	int		b;
	int		in;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	b = ft_len(sep) * (size);
	i = 0;
	while (i < size)
	{
		in = 0;
		while (strs[i][in])
			in++;
		b += in;
		i++;
	}
	r = (char *)malloc(b * sizeof(char));
	if (r == NULL)
		return (0);
	return (ft_strjoin2(r, strs, sep, size));
}

int		main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc(4 * sizeof(strs));
	strs[0] = "lol";
	strs[1] = "1234";
	strs[2] = "poiuic";
	strs[3] = "1234";
	separator = " ";
	index = 0;
	while (index < 4)
	{
		result = ft_strjoin(index, strs, separator);
		printf("result with size = %d : $%s$\n", index, result);
		free(result);
		index++;
	}
}