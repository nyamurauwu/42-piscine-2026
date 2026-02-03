/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:44:05 by landrade          #+#    #+#             */
/*   Updated: 2026/02/01 17:45:45 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*move;

	move = dest;
	while (n-- > 0)
	{
		*dest++ = *src;
		src += (*src != '\0');
	}
	return (move);
}
/*
int	main(void)
{
	char	dest[50];
	char	src[] = "aaaaaaaaaaaaaaaa";

	ft_strncpy(dest, src, 55);
	printf("Resultado: %s\n", dest);
	return (0);
}
	*/
