/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:50:46 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 16:31:59 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	visibility(int **g_grid, int **g_views);
bool	grid_complete(int **g_grid);

extern int	g_size;

bool	valid_placement(int **g_grid, int row, int col, int height)
{
	int	index;

	index = 0;
	while (index < g_size)
	{
		if (g_grid[row][index] == height || g_grid[index][col] == height)
		{
			return (false);
		}
		index++;
	}
	return (true);
}

void	initialize_grid(int **g_grid)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while (index < g_size)
	{
		while (index2 < g_size)
		{
			g_grid[index][index2] = 0;
			index2++;
		}
		index++;
	}
}

bool	solve(int **g_grid, int **g_views, int row, int col)
{
	int	height;

	height = 1;
	if (row == g_size)
		return (visibility(g_grid, g_views));
	if (col == g_size)
		return (solve(g_grid, g_views, row + 1, 0));
	while (height <= g_size)
	{
		if (valid_placement(g_grid, row, col, height))
		{
			g_grid[row][col] = height;
			if (solve(g_grid, g_views, row, col + 1))
			{
				return (true);
			}
			g_grid[row][col] = 0;
		}
		height++;
	}
	return (false);
}
