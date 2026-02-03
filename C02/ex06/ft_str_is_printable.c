/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:44:34 by landrade          #+#    #+#             */
/*   Updated: 2026/02/01 17:44:35 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "aB3/!'.;Ko+";
	str2 = "aB3/!'.;Ko±";
	printf("%s is printable? %d\n", str1, ft_str_is_printable(str1));
	printf("%s is printable? %d\n", str2, ft_str_is_printable(str2));
}
*/
