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

int	ft_is_space(char a)
{
	if (a == 32 || a == '\t' || a == '\v' || a == '\f' || a == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	save;

	sign = 1;
	i = 0;
	save = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			save = (save * 10) + (str[i] - 48);
		else
			break ;
		i++;
	}
	return (save * sign);
}
