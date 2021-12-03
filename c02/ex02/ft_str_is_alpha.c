/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:46:40 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:42 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	ritorno;

	i = 0;
	ritorno = 1;
	while (str[i] != "\0")
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			ritorno = 1;
			i++;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z'))
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
