/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:06:36 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/01 14:06:39 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	ritorno;

	i = 0;
	ritorno = 1;
	while (str[i] != "\0")
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			ritorno = 1;
			i++;
		}
		else
		{
			ritorno = 0;
			return (ritorno);
		}
	}
	return (ritorno);
}
