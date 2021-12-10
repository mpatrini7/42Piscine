/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:33:14 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/09 11:33:15 by mpatrini         ###   ########.fr       */
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

char	*ft_strjoin2(char *r, char **strs, char *sep)
{
	int	a;
	int	i;
	int	in;

	i = 0;
	a = 0;
	while (strs[i])
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

	r = NULL;
	if (size == 0)
		return (r);
	b = ft_len(sep) * (size - 1);
	i = 0;
	while (strs[i])
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
	return (ft_strjoin2(r, strs, sep));
}
