/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 04:52:59 by jpflegha          #+#    #+#             */
/*   Updated: 2025/11/11 05:33:06 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts a string to a floating-point number (double)
/// The function skips leading whitespace, handles an optional '+' or '-' sign,
/// and converts both the integer and fractional parts of the number.
/// It stops parsing when a non-numeric character (other than '.') is encountered.
/// @param char *str 
/// @return double
float	ft_atof(const char *str)
{
	double	result = 0.0;
	double	frac = 0.0;
	int		sign = 1;
	double	divisor = 1.0;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		   *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			frac = frac * 10 + (*str - '0');
			divisor *= 10;
			str++;
		}
		result += frac / divisor;
	}

	return (result * sign);
}