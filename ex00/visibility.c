/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:54:20 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 14:10:53 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

extern int	g_size;

bool	visibility_left(int **g_grid, int **g_views)
{
	int	index1;
	int	index2;
	int	visible;
	int	max_height;

	index1 = 0;
	while (index1 < g_size)
	{
		index2 = 0;
		visible = 0;
		max_height = 0;
		while (index2 < g_size)
		{
			if (g_grid[index1][index2] > max_height)
			{
				max_height = g_grid[index1][index2];
				visible++;
			}
			index2++;
		}
		if (visible != g_views[2][index1])
			return (false);
		index1++;
	}
	return (true);
}

bool	visibility_right(int **g_grid, int **g_views)
{
	int	index1;
	int	index2;
	int	visible;
	int	max_height;

	index1 = 0;
	while (index1 < g_size)
	{
		index2 = 0;
		visible = 0;
		max_height = 0;
		while (index2 < g_size)
		{
			if (g_grid[index1][g_size - 1 - index2] > max_height)
			{
				max_height = g_grid[index1][g_size - 1 - index2];
				visible++;
			}
			index2++;
		}
		if (visible != g_views[3][index1])
			return (false);
		index1++;
	}
	return (true);
}

bool	visibility_top(int **g_grid, int **g_views)
{
	int	index1;
	int	index2;
	int	visible;
	int	max_height;

	index2 = 0;
	while (index2 < g_size)
	{
		index1 = 0;
		visible = 0;
		max_height = 0;
		while (index1 < g_size)
		{
			if (g_grid[index1][index2] > max_height)
			{
				max_height = g_grid[index1][index2];
				visible++;
			}
			index1++;
		}
		if (visible != g_views[0][index2])
			return (false);
		index2++;
	}
	return (true);
}

bool	visibility_bottom(int **g_grid, int **g_views)
{
	int	index1;
	int	index2;
	int	visible;
	int	max_height;

	index2 = 0;
	while (index2 < g_size)
	{
		index1 = 0;
		visible = 0;
		max_height = 0;
		while (index1 < g_size)
		{
			if (g_grid[g_size - 1 - index1][index2] > max_height)
			{
				max_height = g_grid[g_size - 1 - index1][index2];
				visible++;
			}
			index1++;
		}
		if (visible != g_views[1][index2])
			return (false);
		index2++;
	}
	return (true);
}

bool	visibility(int **g_grid, int **g_views)
{
	if (visibility_left(g_grid, g_views))
	{
		if (visibility_right(g_grid, g_views))
		{
			if (visibility_top(g_grid, g_views))
			{
				if (visibility_bottom(g_grid, g_views))
					return (true);
				else
					return (false);
			}
			else
				return (false);
		}
		else
			return (false);
	}
	else
	{
		return (false);
	}
}
