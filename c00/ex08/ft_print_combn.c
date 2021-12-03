/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:01:09 by mpatrini          #+#    #+#             */
/*   Updated: 2021/11/29 16:01:16 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr3(int ***arr, int nb)
{
	while (arr[9] <= (1 - nb))
	{
		write(1, arr, (nb - 1));
		write(1, ", ", 2);
		arr[9]++;
	}
}

void	ft_putnbr2(int **arr, int nb)
{
	while (arr[6] <= (4 - nb))
	{
		arr[7] = arr[6] + 1;
		while (arr[7] <= (3 - nb))
		{
			arr[8] = arr[7] + 1;
			while (arr[8] <= (2 - nb))
			{
				arr[9] = arr[8] + 1;
				ft_putnbr3(&arr, nb);
				arr[8]++;
			}
			arr[7]++;
		}
		arr[6]++;
	}
}

void	ft_putnbr1(int *arr, int nb)
{
	while (arr[3] <= (7 - nb))
	{
		arr[4] = arr[3] + 1;
		while (arr[4] <= (6 - nb))
		{
			arr[5] = arr[4] + 1;
			while (arr[5] <= (5 - nb))
			{
				arr[6] = arr[5] + 1;
				ft_putnbr2(&arr, nb);
				arr[5]++;
			}
			arr[4]++;
		}
		arr[3]++;
	}
}

void	ft_print_combn(int nb)
{
	int	arr[9];

	arr[0] = 0;
	while (arr[0] <= (10 - nb))
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= (9 - nb))
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= (8 - nb))
			{
				arr[3] = arr[2] + 1;
				ft_putnbr1(&arr, nb);
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}
