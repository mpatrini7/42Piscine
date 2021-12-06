/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:58:40 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/01 18:46:39 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

void	ft_strcapitalize2(char *str)
{
	char	a;
	char	b;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		b = str[i - 1];
		if (i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			i++;
		}
		else if (b < 48 || b > 122 || (b > 57 && b < 65) || (b > 90 && b < 97))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			i++;
		}
		else
			i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	ft_strlowcase(str);
	ft_strcapitalize2(str);
	return (str);
}
