/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:45:21 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/02/25 14:04:27 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	temp;

	temp = 0;
	while (*str != '\0')
	{
		temp++;
		str++;
	}
	return (temp);
}

void	error(int error_code)
{
	const char	*error_messages[4];
	int			strlen;

	error_messages[0] = "Error";
	error_messages[1] = "Error";
	error_messages[2] = "Error";
	error_messages[3] = "Error";
	strlen = ft_strlen(error_messages[error_code]);
	write (2, error_messages[error_code], strlen);
	write(2, "\n", 1);
	exit(1);
}

/*error_messages[0] = "Unknown error";
	error_messages[1] = "Invalid number of arguments. Expected 16 digits.";
	error_messages[2] = "Invalid input. Each char must be a digit from 1 to 4.";
	error_messages[3] = "Puzzle unsolvable.";*/
