/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:33:29 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/10 16:12:26 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_is_space(char a)
{
	if (a == 32 || a == '\t' || a == '\v' || a == '\f'
		|| a == '\r' || a == '\n')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_valid_base(char *str)
{
	char	*current;
	int		i;
	int		o;

	current = str;
	i = 0;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*current)
	{
		if (ft_is_space(*current) || *current == '+' || *current == '-')
			return (0);
		current++;
	}
	while (i < current - str)
	{
		o = i + 1;
		while (o < current - str)
			if (str[i] == str[o++])
				return (0);
		i++;
	}
	return (1);
}

int	ft_base(char *base, char a)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	mult;
	int	save;
	int	sign;
	int	baseb;

	save = 0;
	sign = 1;
	if (ft_valid_base(base) == 0)
		return (0);
	mult = ft_strlen(base);
	while (ft_is_space(*str) == 1)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_base(base, *str) != -1)
	{
		baseb = ft_base(base, *str);
		save = (save * mult) + baseb;
		str++;
	}
	return (save * sign);
}
