/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:15:08 by landrade          #+#    #+#             */
/*   Updated: 2026/02/04 17:19:50 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int		resultado;

	s1 = "";
	s2 = "";
	resultado = ft_strcmp(s1, s2);
	printf("O resultado da comparacao: %d\n", resultado);
	return (0);
}
*/
