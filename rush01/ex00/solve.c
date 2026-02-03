/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:54:38 by landrade          #+#    #+#             */
/*   Updated: 2026/01/25 20:53:08 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_double(int grid[4][4], int row, int col, int num);
int	check_up(int grid[4][4], int *clue, int col);
int	check_down(int grid[4][4], int *clue, int col);
int	check_left(int grid[4][4], int *clue, int row);
int	check_right(int grid[4][4], int *clue, int row);
int	solve(int grid[4][4], int clues[4][4]);

int	check_limits(int grid[4][4], int clues[4][4], int row, int col)
{
	if (col == 3)
	{
		if (check_left(grid, clues[2], row) == 1
			|| check_right(grid, clues[3], row) == 1)
			return (1);
	}
	if (row == 3)
	{
		if (check_up(grid, clues[0], col) == 1
			|| check_down(grid, clues[1], col) == 1)
			return (1);
	}
	return (0);
}

int	recursive_step(int grid[4][4], int clues[4][4], int row, int col)
{
	int	num;

	num = 1;
	while (num <= 4)
	{
		if (check_double(grid, row, col, num) == 0)
		{
			grid[row][col] = num;
			if (check_limits(grid, clues, row, col) == 0)
			{
				if (solve(grid, clues) == 1)
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve(int grid[4][4], int clues[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (grid[row][col] == 0)
				return (recursive_step(grid, clues, row, col));
			col++;
		}
		row++;
	}
	return (1);
}
