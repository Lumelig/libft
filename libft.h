/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:39:04 by jpflegha          #+#    #+#             */
/*   Updated: 2024/10/10 15:43:02 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int	ft_isalnum(int i);

int	ft_isdigit(int i);

int	ft_isascii(int i);

int	ft_isalnum(int i);

int	ft_isprint(int i);

int	ft_strlen(const char *str)

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n);
#endif