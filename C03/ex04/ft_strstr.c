/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:15:35 by landrade          #+#    #+#             */
/*   Updated: 2026/02/04 17:18:32 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*aux_s;
	char	*aux_x;

	aux_s = str;
	aux_x = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		aux_s = str;
		aux_x = to_find;
		while (*aux_x != '\0' && *aux_s == *aux_x)
			*aux_s++ = *aux_x++;
		if (*aux_x == '\0')
			return (str);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "42sp";
	char find[] = "sp";
	printf("%s", ft_strstr(str, find));
	return (0);
}
*/
