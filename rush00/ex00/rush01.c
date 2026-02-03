/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:21:01 by adedias-         #+#    #+#             */
/*   Updated: 2026/01/18 16:21:01 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_roll(int x, char start, char middle, char end);

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
	{
		ft_putchar('\n');
		return ;
	}
	print_roll(x, '/', '*', '\\');
	i = 2;
	while (i < y)
	{
		print_roll(x, '*', ' ', '*');
		i = i + 1;
	}
	if (y > 1)
	{
		print_roll(x, '\\', '*', '/');
	}
}

void	print_roll(int x, char start, char middle, char end)
{
	int	i;

	if (x >= 1)
	{
		ft_putchar(start);
	}
	i = 1;
	while (i < x - 1)
	{
		ft_putchar(middle);
		i++;
	}
	if (x > i)
	{
		ft_putchar(end);
	}
	ft_putchar('\n');
}
