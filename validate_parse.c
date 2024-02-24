/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:07:49 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/24 15:12:45 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	**g_views;

void error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	valid_input(int argc, char *argv[])
{
	int	index;

	index = 1;
	if (argc != 17)
		error();
	while (index < argc)
	{
		if (argv[index][0] < '1' || argv[index][0] > '4')
			error();
		if (argv[index][1])
			error();
		index++;
	}
}

void	parse_input(char *argv[])
{
	int	side;
	int	position;
	int	index;

	side = 0;
	index = 0;
	g_views = (int **)malloc(4 * sizeof(int *));
	while (index < 4)
	{
		g_views[index] = (int *)malloc(4 * sizeof(int));
		index++;
	}
	index = 1;
	while (side < 4)
	{
		position = 0;
		while (position < 4)
		{
			g_views[side][position] = argv[index][0] - '0';
			position++;
			index++;
		}
		side++;
	}
}

int	main(int argc, char *argv[])
{
	valid_input(argc, argv);
	parse_input(argv);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d", g_views[i][j]);
	}
}
