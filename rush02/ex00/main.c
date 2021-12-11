/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:54:20 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/11 16:54:22 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (dest[i])
		i++;
	while (src[o] != '\0')
	{
		dest[i] = src[o];
		i++;
		o++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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

void	rec_print(char *arr, int size, int i, /*----stringa passata da argv----*/, char *dict)
{
	char	*temp;
	int		con;
	char	*temp2;
	int		b;
	int		c;
	
	if(i == (size -1))
		return ;
	temp = (char *)malloc(500 * sizeof(char));
		if(i == (size - 1) && (size - 2) == 49)
		{

		}
		else if(i == (size -2))
		{

		}
		else
		{
			while(1) // modificare ter;
			{
				c = 0;
				b = size - i;
				temp2[0] = //numero del centinaio
				while(b > 1)
				{
					temp2[c] == 0;
					c++;
					b++;
				}
				if(ter -> size == 1 && ft_strcmp(temp2, xxxxxxx)) //add full string to compare with the number
				{
					ft_strcat(temp, ter -> text); //modifier
				}
				if(ter -> size == (size - i))
				{
					temp = ter -> text; //modifier
				}
			}
		}
	ft_strcat(arr, temp);
	free (temp);
	i++;
	rec_print(arr, size, i, av[1], *dict);
}

int	main(int ac, char **av)
{
	char	*arr;
	int		i;
	int		size;
	int		size2;
	char	*final;

	arr = (char *)malloc(50000 * sizeof(char));
	i = 0;
	rec_print(arr, size, int i, /*----stringa passata da argv----*/, char *dict);
	size2 = ft_strlen(arr);
	final = (char *)malloc(size2 * sizeof(char));
	final = ft_strcpy(final, arr);
	ft_putstr(final);
	free(arr);
	free(final);
	return (0);
}