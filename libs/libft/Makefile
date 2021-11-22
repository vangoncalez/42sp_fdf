# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 14:13:56 by vaferrei          #+#    #+#              #
#    Updated: 2021/11/14 21:41:17 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_numberlen.c \
			ft_hexlen.c \
			get_next_line.c \
			ft_atoi_base.c

BSRCS 	= 	ft_lstnew.c\
       		ft_lstadd_front.c\
       		ft_lstsize.c\
       		ft_lstlast.c\
       		ft_lstadd_back.c\
       		ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${BSRCS:.c=.o}

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
	rm -f ${OBJS}
	rm -f ${BOBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: all
	${CC} main.c libft.a -o teste

bonus: ${BOBJS}
	ar -rcs $(NAME) ${BOBJS}

.PHONY: all, bonus, clean, fclean, re
