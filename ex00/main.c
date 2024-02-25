/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:45:59 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 14:13:00 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int	**g_grid;
int	**g_views;
int	g_size;

void	initialize_grid(int **g_grid);
void	valid_input(int argc, char *argv[]);
bool	solve(int **g_grid, int **g_views, int row, int col);
void	error(int error_code);
int		ft_strlen(const char *str);

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_res(int **g_grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			print_char(g_grid[i][j] + '0');
			if (j != g_size - 1)
				print_char(' ');
			j++;
		}
		print_char('\n');
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc != 2)
		error(1);
	g_size = (ft_strlen(argv[1]) + 1) / 8;
	index = 0;
	g_grid = (int **)malloc(g_size * sizeof(int *));
	while (index < g_size)
		g_grid[index++] = (int *)malloc(g_size * sizeof(int));
	initialize_grid(g_grid);
	valid_input(argc, argv);
	if (solve(g_grid, g_views, 0, 0))
		print_res(g_grid);
	else
		error(3);
	index = 0;
	while (index < g_size)
	{
		free(g_grid[index]);
		free(g_views[index]);
		index++;
	}
	free(g_grid);
	free(g_views);
	return (0);
}
