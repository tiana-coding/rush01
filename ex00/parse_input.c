/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:50:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 14:12:38 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	**g_views;
extern int	g_size;

void	error(int error_code);

void	valid_input(int argc, char *argv[])
{
	int	index;

	index = 0;
	if (argc != 2)
	{
		error(1);
	}
	g_views = (int **)malloc(g_size * sizeof(int *));
	while (index < g_size)
	{
		g_views[index] = (int *)malloc(g_size * sizeof(int));
		index++;
	}
	index = 0;
	while (index < g_size * 4)
	{
		if (argv[1][index * 2] < '1' || argv[1][index * 2] > g_size + '0')
			error(2);
		else
			g_views[index / g_size][index % g_size] = argv[1][index * 2] - '0';
		if (argv[1][(index * 2) + 1] != ' ' && index < (g_size * 4) - 1)
			error(2);
		index++;
	}
}
