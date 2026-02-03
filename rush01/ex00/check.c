/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landrade <landrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:43:34 by landrade          #+#    #+#             */
/*   Updated: 2026/01/25 20:53:14 by landrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_double(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_up(int grid[4][4], int *clue, int col)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i++;
	}
	if (count != clue[col])
		return (1);
	return (0);
}

int	check_down(int grid[4][4], int *clue, int col)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			count++;
		}
		i--;
	}
	if (count != clue[col])
		return (1);
	return (0);
}

int	check_left(int grid[4][4], int *clue, int row)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i++;
	}
	if (count != clue[row])
		return (1);
	return (0);
}

int	check_right(int grid[4][4], int *clue, int row)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			count++;
		}
		i--;
	}
	if (count != clue[row])
		return (1);
	return (0);
}
