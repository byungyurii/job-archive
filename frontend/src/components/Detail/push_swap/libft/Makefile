# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 02:33:25 by gbyun             #+#    #+#              #
#    Updated: 2021/01/14 03:11:57 by gbyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isascii.c\
	ft_memcmp.c\
	ft_putnbr_fd.c\
	ft_strlcat.c\
	ft_strrchr.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_memcpy.c\
	ft_putstr_fd.c\
	ft_strlcpy.c\
	ft_strtrim.c\
	ft_bzero.c\
	ft_isprint.c\
	ft_memmove.c\
	ft_split.c\
	ft_strlen.c\
	ft_substr.c\
	ft_calloc.c\
	ft_itoa.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strmapi.c\
	ft_tolower.c\
	ft_isalnum.c\
	ft_memccpy.c\
	ft_putchar_fd.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_toupper.c\
	ft_isalpha.c\
	ft_memchr.c\
	ft_putendl_fd.c\
	ft_strjoin.c\
	ft_strnstr.c

BONUS_SRC = ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcu $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS) $(OBJS)
	ar rcu $(NAME) $(OBJS) $(BONUS_OBJS)


clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
