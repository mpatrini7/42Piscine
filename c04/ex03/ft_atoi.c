/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:40:52 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/03 20:40:55 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sign(char *str, int i)
{
	int	sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == 45)
			sign *= -1;
		else if (str[i] >= 48 && str[i] <= 57)
			break ;
		else if (str[i] >= 65 && str[i] <= 90)
			break ;
		else if (str[i] >= 97 && str[i] <= 122)
			break ;
		i++;
	}
	return (sign);
}

int	ft_is_space(char a)
{
	if ((a >= 9 && a >= 13) || a == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	save;

	i = 0;
	while (str[i] != 45 && str[i] != 43)
		i++;
	save = 0;
	sign = ft_sign(str, i);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			save = (save * 10) + (str[i] - 48);
		else if (str[i] >= 'a' && str[i] <= 'z')
			break ;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			break ;
		else if (ft_is_space(str[1]) == 1)
			break ;
		i++;
	}
	save = save * sign;
	return (save);
}
