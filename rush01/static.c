/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:19 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:21 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_static_four(int *game, int *pos, int size);
void	ft_static_four2(int *game, int *pos, int size);
void	ft_static_four3(int *game, int *pos, int size);
void	ft_static_four4(int *game, int *pos, int size);
void	ft_static_threetwo(int *game, int *pos, int size);

void    ft_static_one(int *game, int *pos, int size)
{
    int i;

    i = 0;
    while(i < size)
	{
        if(pos[i] == 1)
        {
            if(i < (size / 4))
                game[i] = (size / 4);
            else if (i >= (size / 4) && i < (size / 2))
                game[i + (size / 2)] = (size / 4);
            else if (i >= (size / 2) && i < (size - (size / 4)))
                game[(i % 4) * 4] = (size / 4);
            else if (i > (size - (size / 4)))
                game[(((i % 4) * 4) + ((size / 4) - 1))] = (size / 4);
        }
        i++;
    }
}

void    ft_static_onetwo(int *game, int *pos, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if(i < (size /4) || (i >= (size / 2) && i < (size - (size / 4))))
		{
			if(pos[i] == 2 && pos[i + (size/4)] == 1)
			{
				if(i < (size / 4))
					game[i] = (size / 4) - 1;
				else if (i >= (size / 2) && i < (size - (size / 4)))
					game[(size / 4) * (i % (size / 4))] = (size / 4) - 1;
			}
		}
		i++;
	}
}

void    ft_static_twoone(int *game, int *pos, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if((i >= (size / 4) && i < (size / 2)) || i >= (size - (size / 4)))
		{
			if(pos[i] == 2 && pos[i - (size/4)] == 1)
			{
				if (i >= (size / 4) && i < (size / 2))
					game[((size / 4) * ((size / 4) - 1) + (i % (size / 4)))] =  (size / 4) - 1;
				else if (i > (size - (size / 4)))
					game[(i % 4) * (size / 4) + ((size / 4) - 1)] = (size / 4) - 1;
			}
		}
		i++;
	}
}


void	ft_static_twothree(int *game, int *pos, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if(i < (size /4) || (i >= (size / 2) && i < (size - (size / 4))))
		{
			if(pos[i] == 2 && pos[i + (size/4)] == 3)
			{
				if(i < (size / 4))
					game[i + size / 4] = size / 4;
				else if (i >= (size / 2) && i < (size - (size / 4)))
					game[(size / 4) * (i % (size / 4)) + 1] = size / 4;
			}
		}
		i++;
	}
}

void    ft_static(int *game, int *pos, int size)
{
    ft_static_one(game, pos, size);
    ft_static_four(game, pos, size);
    ft_static_four2(game, pos, size);
    ft_static_four3(game, pos, size);
    ft_static_four4(game, pos, size);
    ft_static_onetwo(game, pos, size);
    ft_static_twoone(game, pos, size);
    ft_static_twothree(game, pos, size);
    ft_static_threetwo(game, pos, size);
}