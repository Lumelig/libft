/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:28:08 by jpflegha          #+#    #+#             */
/*   Updated: 2025/03/27 19:57:17 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\r' || *str == '\f' || *str == '\v') {
		str++;
	}
	if (*str == '-' || *str == '+') {
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9') {
		result = result * 10 + (*str - '0');
		str++;
	}

	return (result * sign);
}
