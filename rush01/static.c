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

void    ft_static_one(int &game, int &*pos, int size)
{
    int i;

    i =0
    while(*pos[i])
        if(*pos[i] == 1)
        {
            if(i < (size / 4))
                *game[i] = (size / 4);
            else if (i >= (size / 4) && i < (size / 2))
                *game[i + (size / 2)] = (size / 4);
            else if (i >= (size / 2) && i < (size - (size / 4)))
                *game[(i % 4) * 4] = (size / 4);
            else if (i > (size - (size / 4)))
                *game[(((i % 4) * 4) + ((size / 4) - 1))] = (size / 4);
        }
        i++;
    }
}

void	ft_static_four(int &game, int &*pos, int size)
{
	int	i;
	int	v;
	int	f;

	i = 0;
	while(*pos[i])
		v = 0;
		f = i;
		if(i < (size / 4))
		{
			while(v != (size / 4))
			{
				*game[f + (size / 4)] = v;
				v++;
				f++;
				}
		}
		else if (i >= (size / 4) && i < (size / 2))
		{
			f = 0;
			while(v != (size / 4))
			{
				*game[(size / 2 + i) - f] = v;
				v++;
				f += (size / 4);
			}
		}
		i++;
	}
}

void    ft_static_four2(int &game, int &*pos, int size)
{
    int i;
    int v;
    int f;

    i = 0;
    while(*pos[i])
        v = 0;
        if(*pos[i] == (size / 4))
        {
            f = i;
            if(i >= (size / 2) && i < (size - (size / 4)))
            {
                while(v != (size / 4))
                {
                    *game[f + (size / 4)] = v;
                    v++;
                    f++;
                }
            }
            else if (i > (size - (size / 4)))
            {   
                f = 0;
                while(v != (size / 4))
                {
                    *game[(size / 2 + i) - f] = v;
                    v++;
                    f += (size / 4);
                }
            }
        }
        i++;
    }
}
void    ft_static_onetwo(int &game, int &*pos, int size)
{
    int i;

    i =0
    while(*pos[i])
        if(*pos[i] == 1 && *pos[i + (size/4)] == 2)
        {
        {
            if(i < (size / 4))
                *game[i] = 4;
            else if (i >= (size / 4) && i < (size / 2))
                *game[i + (size / 2)] = 4;
            else if (i >= (size / 2) && i < (size - (size / 4)))
                *game[(i % 4) * 4] = 4;
            else if (i > (size - (size / 4)))
                *game[(((i % 4) * 4) + ((size / 4) - 1))] = 4;
        }
        }
        i++;
    }
}

void    ft_static_twoone(int &game, int &*pos, int size)
{
    int i;

    i =0
    while(*pos[i])
        if(*pos[i] == 1 && *pos[i + (size/4)] == 2)
        {
        {
            if(i < (size / 4))
                *game[i] = (size / 4);
            else if (i >= (size / 4) && i < (size / 2))
                *game[i + (size / 2)] = (size / 4);
            else if (i >= (size / 2) && i < (size - (size / 4)))
                *game[(i % 4) * 4] = (size / 4);
            else if (i > (size - (size / 4)))
                *game[(((i % 4) * 4) + ((size / 4) - 1))] = (size / 4);
        }
        }
        i++;
    }
}

void    ft_static_twothree(int &game, int &*pos, int size)
{
    int i;

    i =0
    while(*pos[i])
        if(*pos[i] == 3 && *pos[i + (size/4)] == 2)
        {
        {
            if(i < (size / 4))
                *game[i] = 4;
            else if (i >= (size / 4) && i < (size / 2))
                *game[i + (size / 2)] = 4;
            else if (i >= (size / 2) && i < (size - (size / 4)))
                *game[(i % 4) * 4] = 4;
            else if (i > (size - (size / 4)))
                *game[(((i % 4) * 4) + ((size / 4) - 1))] = 4;
        }
        }
        i++;
    }
}

}

void    ft_static(int &game, int &*pos, int size)
{
    ft_static_one(int &game, int &*pos, int size);
    ft_static_onetwo(int &game, int &*pos, int size);
    ft_static_twoone(int &game, int &*pos, int size);
    ft_static_twothree(int &game, int &*pos, int size);
    ft_static_threetwo(int &game, int &*pos, int size);
    ft_static_four(int &game, int &*pos, int size);
    ft_static_four2(int &game, int &*pos, int size);
    ft_static_four3(int &game, int &*pos, int size);
    ft_static_four4(int &game, int &*pos, int size);
}