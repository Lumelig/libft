/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:07:46 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/28 15:37:48 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static void	skip_whitespace_and_check_sign(const char **str, int *sign)
{
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\r'
		|| **str == '\f' || **str == '\v')
	{
		(*str)++;
	}
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

static long	handle_conversion_and_check_overflow(const char *str, int sign)
{
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && (*str
						- '0') > LONG_MAX % 10)))
		{
			errno = ERANGE;
			return (LONG_MAX);
		}
		if (sign == -1 && (res > -(LONG_MIN / 10) || (res == -(LONG_MIN / 10)
					&& (*str - '0') > -(LONG_MIN % 10))))
		{
			errno = ERANGE;
			return (LONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	skip_whitespace_and_check_sign(&str, &sign);
	result = handle_conversion_and_check_overflow(str, sign);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str != '\0')
	{
		errno = EINVAL;
		return (0);
	}
	return (result * sign);
}
