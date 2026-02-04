/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:15:25 by landrade          #+#    #+#             */
/*   Updated: 2026/02/04 17:21:51 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)

{
	char	*move;

	move = dest;
	while (*move)
		move++;
	while (*src)
		*move++ = *src++;
	*move = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void) {
	char dest[20] = "Hello, ";
	char src[] = "World!";

	ft_strcat(dest, src);
	printf("%s", dest);
	return (0);
}
*/
