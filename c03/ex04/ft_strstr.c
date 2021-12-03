/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:00:22 by mpatrini          #+#    #+#             */
/*   Updated: 2021/12/02 14:00:25 by mpatrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	in;
	int	a;

	i = 0;
	in = 0;
	a = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[in] && str[i])
		{
			i++;
			in++;
			if (to_find[in] == '\0')
				return (&str[i - in]);
		}
		in = 0;
		a++;
		i = a;
	}
	return (0);
}
