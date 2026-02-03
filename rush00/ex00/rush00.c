/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:07:28 by landrade          #+#    #+#             */
/*   Updated: 2026/01/18 18:08:46 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int width, char left, char middle, char right)
{
	int	pos;

	if (width <= 0)
		return ;
	ft_putchar(left);
	pos = 1;
	while (pos < width - 1)
	{
		ft_putchar(middle);
		pos++;
	}
	if (width > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	line;

	if (x <= 0 || y <= 0)
		return ;
	print_line(x, 'o', '-', 'o');
	line = 0;
	while (line < y - 2)
	{
		print_line(x, '|', ' ', '|');
		line++;
	}
	if (y > 1)
		print_line(x, 'o', '-', 'o');
}
