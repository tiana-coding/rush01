/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:39:11 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/24 16:28:09 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	**g_grid;

bool	duplicate_in_row(int **g_grid)
{
	bool	found[5];
	int	index1;
	int	index2;
	int	num;

	index1 = 0;
	while (index1 < 4)
	{
		index2 = 0;
		while (index2 < 5)
		{
			found[index2] = false;
			index2++;
		}
		index2 = 0;
		while (index2 < 4)
		{
			num = g_grid[index1][index2];
			if (found[num])
				return (true);
			found[num] = true;
			index2++;
		}
		index1++;
	}
	return (false);
}

bool duplicate_in_column(int **g_grid)
{
    bool    found[5];
    int index1;
    int index2;
    int num;

    index2 = 0;
    while (index2 < 4)
    {
        index1 = 0;
        while (index1 < 5)
        {
            found[index1] = false;
            index1++;
        }
        index1 = 0;
        while (index1 < 4)
        {
            num = g_grid[index1][index2];
            if (found[num])
                return (true);
            found[num] = true;
            index1++;
        }
        index2++;
    }
	return (false);
}

bool valid_grid(int **g_grid)
{
	if (duplicate_in_row(g_grid) || duplicate_in_column(g_grid))
		return (false);
	else
		return (true);
}

int main() {

	int grid_values[4][4] = {{1, 1, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
		// Define and initialize a 4x4 grid
    int **g_grid = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++) {
        g_grid[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++) {
            // Initialize the grid with some sample values
            g_grid[i][j] = grid_values[i][j];
        }
    }

    if (!duplicate_in_row(g_grid))
		printf("%s", "rows good\n");
	else 
		printf("%s", "rows bad\n");
	if (!duplicate_in_column(g_grid))
		printf("%s", "columns good\n");
    else
        printf("%s", "columns bad\n");

	if (valid_grid(g_grid))
		printf("%s", "grid good\n");
    else
        printf("%s", "grid bad\n");

    // Free the memory allocated for the grid
    for (int i = 0; i < 4; i++) {
        free(g_grid[i]);
    }
    free(g_grid);

    return 0;
}
