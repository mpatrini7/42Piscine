/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:58:09 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/08 22:58:12 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		else if (s1[i] < s2[i])
		{
			return (-1);
		}
	}
	if (s2[i] != '\0')
		return (-1);
	return (0);
}

void	ft_swap(char **av, int ac)
{
	int		i;
	int		i2;
	char	*swap;

	i = 1;
	while (i < ac)
	{
		i2 = i + 1;
		while (i2 < ac)
		{
			if (ft_strcmp(av[i], av[i2]) > 0)
			{
				swap = av[i];
				av[i] = av[i2];
				av[i2] = swap;
			}
			i2++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		b;

	ft_swap(av, ac);
	b = 1;
	while (b < ac)
	{
		i = 0;
		while (av[b][i])
		{
			ft_putchar(av[b][i]);
			i++;
		}
		ft_putchar('\n');
		b++;
	}
}
