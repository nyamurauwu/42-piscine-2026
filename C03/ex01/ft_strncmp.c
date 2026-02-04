/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:15:14 by landrade          #+#    #+#             */
/*   Updated: 2026/02/04 17:19:53 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2 || *s1 == '\0')
		{
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int		resultado;

	s1 = "a";
	s2 = "";
	resultado = ft_strncmp(s1, s2,3);
	printf("O resultado da comparacao: %d\n", resultado);
	return (0);
}
	*/
