/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:27:08 by jpflegha          #+#    #+#             */
/*   Updated: 2024/10/10 17:35:59 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(int i)
{
    if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')
        || (i >= '0' && i<= '9'))
    {
        return (1);
    }
    return (0);
}