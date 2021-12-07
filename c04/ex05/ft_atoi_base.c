/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:48:56 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/03 23:48:58 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char a)
{
	if (a == 32 || a == '\t' || a == '\v' || a == '\f' || a == '\r')
		return (1);
	return (0);
}

int	ft_check_same_char(char *base)
{
	int	i;
	int	in;

	i = 0;
	while (base[i])
	{
		in = i + 1;
		while (base[in])
		{
			if (base[i] == base[in])
				return (1);
			in++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi2(char *str)
{
	int	i;
	int	sign;
	int	save;

	sign = 1;
	i = 0;
	save = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			save = (save * 10) + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (save * sign);
}

int	ft_atoi(char *str, int base)
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
			save = (save * base) + (str[i] - 48);
		else
			break ;
		i++;
	}
	return (save * sign);
}

int	ft_atoi_base(char *str, char *base)
{	
	int	at_base;

	if (*base == '\0' || base[1] == '\0')
		return (0);
	if (ft_check_same_char(base) == 1)
		return (0);
	at_base = ft_atoi2(base);
	if (at_base == 0)
		return (0);
	return (ft_atoi(str, at_base));
}
