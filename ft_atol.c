/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:07:46 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/27 20:08:11 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;

	// Skip leading whitespace
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
		   str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;

	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	// Convert digits
	while (str[i] >= '0' && str[i] <= '9')
	{
		// Overflow check for positive numbers
		if (sign == 1 && 
			(res > LONG_MAX / 10 || 
			 (res == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10)))
		{
			errno = ERANGE;
			return LONG_MAX;
		}
		
		// Overflow check for negative numbers
		if (sign == -1 && 
			(res > -(LONG_MIN / 10) || 
			 (res == -(LONG_MIN / 10) && (str[i] - '0') > -(LONG_MIN % 10))))
		{
			errno = ERANGE;
			return LONG_MIN;
		}

		res = res * 10 + (str[i] - '0');
		i++;
	}

	// Skip trailing whitespace
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	// Check for invalid characters after number
	if (str[i] != '\0')
	{
		errno = EINVAL;
		return 0;
	}

	return res * sign;
}