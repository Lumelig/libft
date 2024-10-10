/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:28:08 by jpflegha          #+#    #+#             */
/*   Updated: 2024/10/10 18:35:54 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	while (*str == ' ' || (*str <= 13 && *str >= 9) || 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		neg *= -1;
		str++;
	}
	while (*str >= '0' || *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	return (res * neg);
}
