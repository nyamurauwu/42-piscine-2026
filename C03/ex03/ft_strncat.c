/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:15:29 by landrade          #+#    #+#             */
/*   Updated: 2026/02/04 17:15:29 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int n)

{
	char	*move;

	move = dest;
	while (*move)
	{
		move++;
	}
	while (n-- > 0 && *src)
	{
		*move++ = *src++;
	}
	*move = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main() {
    char src[] = "42";
    char dest[20] = "sp";
    printf("%s", ft_strncat(dest, src, 1));

}
*/
