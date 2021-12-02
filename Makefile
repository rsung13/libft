# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsung <rsung@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 12:56:58 by rsung             #+#    #+#              #
#    Updated: 2021/12/01 11:48:36 by rsung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

HEADER = ./

CC = clang

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c libft.h
	$(CC) $(FLAGS) -o $@ -I $(HEADER) -c $<

$(NAME) : $(OBJS)
	ar rc $@ $^

bonus : $(OBJS) $(BOBJS)
	ar rc $(NAME) $^

clean :
	rm -rf $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all	
