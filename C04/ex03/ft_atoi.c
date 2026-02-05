/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 05:11:00 by landrade          #+#    #+#             */
/*   Updated: 2026/02/05 05:15:17 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi("  ---+--1234ab567")); // Tem que dar 1234
    printf("%d\n", ft_atoi("42"));               // 42
    printf("%d\n", ft_atoi("-2147483648"));      // Min Int
    printf("%d\n", ft_atoi("0"));                // 0
    return (0);
}
*/
