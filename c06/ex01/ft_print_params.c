/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:12:14 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/08 20:12:17 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	b;

	b = 1;
	while(av[b])
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
