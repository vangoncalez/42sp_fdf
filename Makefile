# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 15:22:09 by vaferrei          #+#    #+#              #
#    Updated: 2021/11/26 23:18:56 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

MLX         = ./libs/mlx_linux/libmlx_Linux.a
LIBFT       = ./libs/libft/libft.a

LFTDIR		= ./libs/libft/
MLXDIR		= ./libs/mlx_linux/
INCSDIR		= ./incs
SRCSDIR 	= ./srcs/

SRCS 		= 	$(SRCSDIR)colors.c \
				$(SRCSDIR)error_exit.c \
				$(SRCSDIR)free.c \
				$(SRCSDIR)init.c \
				$(SRCSDIR)instructions.c \
				$(SRCSDIR)keycode.c \
				$(SRCSDIR)main.c \
				$(SRCSDIR)plot_utils.c \
				$(SRCSDIR)plot.c \
				$(SRCSDIR)points.c \
				$(SRCSDIR)utils.c \
				$(SRCSDIR)vector_process.c \
				$(SRCSDIR)vector_rotate.c \
				$(SRCSDIR)vector_view.c \
				$(SRCSDIR)vectors.c

OBJS=$(SRCS:.c=.o)


CFLAGS		= -Wall -Wextra -Werror
CC 			= clang
MLXCFLAGS 	= -lm -lbsd -lmlx -lXext -lX11

RM =rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LFTDIR) -L $(MLXDIR) -lft $(MLXCFLAGS)

$(MLX):
	make -C $(MLXDIR)

$(LIBFT):
	make -C $(LFTDIR)

bonus: all

re: fclean all

rebonus: fclean bonus

clean:
	make clean -C $(LFTDIR)
	$(RM) -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) -rf $(NAME) $(BONUS_OBJ)
	make fclean -C $(LFTDIR)
	make clean -C $(MLXDIR)

.PHONY: clean fclean re rebonus all bonus
