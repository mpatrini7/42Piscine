/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:21:42 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/04 22:21:44 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_static_four(int *game, int **pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (pos[i])
	{
		v = 1;
		f = i;
		if (i < (size / 4))
		{
			while (v != (size / 4))
			{
				game[f + (size / 4)] = v;
				v++;
				f++;
			}
		}
		i++;
	}
}

void	ft_static_four2(int *game, int **pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (pos[i])
	{
		v = 1;
		f = 0;
		if (i >= (size / 4) && i < (size / 2))
		{
			while (v != (size / 4))
			{
				game[(size / 2 + i) - f] = v;
				v++;
				f += (size / 4);
			}
		}
		i++;
	}
}

void	ft_static_four3(int *game, int **pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (pos[i])
	{
		v = 1;
		f = 0;
		if (i >= (size / 2) && i < (size - (size / 4)))
		{
			while (v != (size / 4))
			{
				game[(i % 4) * (size / 4) + f] = v;
				v++;
				f += 1;
			}
		}
		i++;
	}
}

void	ft_static_four4(int *game, int **pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (pos[i])
	{
		v = 1;
		f = 3;
		if (i > (size - (size / 4)))
		{
			while (v != (size / 4))
			{
				game[(i % 4) * (size / 4) + f] = v;
				v++;
				f--;
			}
		}
		i++;
	}
}
