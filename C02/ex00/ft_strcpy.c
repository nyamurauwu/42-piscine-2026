/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:44:00 by landrade          #+#    #+#             */
/*   Updated: 2026/02/01 17:44:00 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*move;

	move = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (move);
}
/*

#include <stdio.h>
#include <string.h>

int main (void)
{
char dest[3] ="";
char src [3] = "aa";
ft_strcpy(dest,src);
printf("%s", dest);
}
*/
