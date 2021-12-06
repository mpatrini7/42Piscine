/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:11:01 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/01 14:11:03 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	ritorno;

	i = 0;
	ritorno = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 32 && str[i] <= 126))
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
