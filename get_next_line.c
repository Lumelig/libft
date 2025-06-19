/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:25:38 by jpflegha          #+#    #+#             */
/*   Updated: 2025/06/19 21:39:46 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*read_file(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_and_null(&remainder), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_null(&buffer), free_and_null(&remainder), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free_and_null(&temp);
		if (!remainder || ft_strchr(remainder, '\n'))
			break ;
	}
	free_and_null(&buffer);
	return (remainder);
}

char	*extract_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder || !remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line[i] = '\0', line);
}

char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;
	int		j;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free_and_null(&remainder);
		return (NULL);
	}
	new_remainder = malloc(ft_strlen(remainder) - i + 1);
	if (!new_remainder)
		return (free_and_null(&remainder), NULL);
	i++;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free_and_null(&remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_file(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	if (!line)
	{
		free_and_null(&remainder);
		return (NULL);
	}
	remainder = update_remainder(remainder);
	return (line);
}
