# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 17:18:56 by jpflegha          #+#    #+#              #
#    Updated: 2025/03/27 20:14:32 by jpflegha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c \
		ft_strlen.c ft_tolower.c ft_toupper.c ft_atoi.c ft_strlcpy.c ft_memmove.c ft_strlcat.c ft_strrchr.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_atol.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c

OBJ = $(SRC:%.c=%.o)

BONUS_OBJS = $(BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $?
	
bonus : $(OBJ) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)

clean :
	rm -rf $(OBJ) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all