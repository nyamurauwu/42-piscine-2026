/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:43:26 by landrade          #+#    #+#             */
/*   Updated: 2026/01/25 20:53:11 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str);
void	inicialize_grid(int grid[4][4]);
void	print_grid(int grid[4][4]);
int		solve(int grid[4][4], int clues[4][4]);
int		parse_args(char *str, int clues[4][4]);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_input(int argc, char **argv, int clues[4][4])
{
	if (argc != 2)
	{
		putstr("Error: Wrong argument count. Usage: ./rush-01 \"...\"\n");
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		putstr("Error: Invalid string length (must be 31 chars).\n");
		return (1);
	}
	if (parse_args(argv[1], clues) == 0)
	{
		putstr("Error: Invalid syntax. Use only digits 1-4 and spaces.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[4][4];

	if (check_input(argc, argv, clues) == 1)
		return (1);
	inicialize_grid(grid);
	if (solve(grid, clues) == 1)
		print_grid(grid);
	else
		putstr("Error: No solution found.\n");
	return (0);
}
