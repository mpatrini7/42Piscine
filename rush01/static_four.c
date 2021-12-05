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

void	ft_static_four(int *game, int *pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (i < size)
	{
		v = 1;
		f = 0;
		if (i < (size / 4) && (pos[i] == (size / 4)))
		{
			while (v <= (size / 4))
			{
				game[i + (f * (size / 4))] = v;
				v++;
				f++;
			}
		}
		i++;
	}
}

void	ft_static_four2(int *game, int *pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (i < size)
	{
		v = 1;
		f = 0;
		if (i >= (size / 4) && i < (size / 2) && (pos[i] == (size / 4)))
		{
			while (v <= (size / 4))
			{
				game[(size / 2 + i) - f] = v;
				v++;
				f += (size / 4);
			}
		}
		i++;
	}
}

void	ft_static_four3(int *game, int *pos, int size)
{
	int	i;
	int	v;
	int	f;
	int	s;

	s = size;
	i = 0;
	while (i < size)
	{
		v = 1;
		f = 0;
		if (i >= (s / 2) && i < (s - (s / 4)) && (pos[i] == (s / 4)))
		{
			while (v <= (s / 4))
			{
				game[(i % 4) * (s / 4) + f] = v;
				v++;
				f++;
			}
		}
		i++;
	}
}

void	ft_static_four4(int *game, int *pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while (i < size)
	{
		v = 1;
		f = (size / 4 - 1);
		if (i >= (size - (size / 4)) && (pos[i] == (size / 4)))
		{
			while (v <= (size / 4))
			{
				game[(i % 4) * (size / 4) + f] = v;
				v++;
				f--;
			}
		}
		i++;
	}
}

void	ft_static_threetwo(int *game, int *pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((i >= (size / 4) && i < (size / 2)) || i >= (size - (size / 4)))
		{
			if (pos[i] == 2 && pos[i - (size / 4)] == 3)
			{
				if (i >= (size / 4) && i < (size / 2))
					game[i + size / 4] = size / 4;
				else if (i > (size - (size / 4)))
					game[(size / 4) * (i % (size / 4)) + 2] = size / 4;
			}
		}
		i++;
	}
}
