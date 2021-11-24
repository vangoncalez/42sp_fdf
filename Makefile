# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 15:22:09 by vaferrei          #+#    #+#              #
#    Updated: 2021/11/23 23:52:07 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf

#libraries
MLX 		= libmlx_Linux.a
LIBFT 		= libft.a

#dirs
LFTDIR		= ./libs/libft/
MLXDIR		= ./libs/mlx_linux/
INCSDIR		= ./incs
SRCSDIR 	= ./srcs/

SRCS 		= 	$(SRCSDIR)colors.c \
				$(SRCSDIR)plot_utils.c \
				$(SRCSDIR)error_exit.c \
				$(SRCSDIR)free.c \
				$(SRCSDIR)init.c \
				$(SRCSDIR)instructions.c \
				$(SRCSDIR)keycode.c \
				$(SRCSDIR)main.c \
				$(SRCSDIR)plot.c \
				$(SRCSDIR)points.c \
				$(SRCSDIR)utils.c \
				$(SRCSDIR)vector_process.c \
				$(SRCSDIR)vector_rotate.c \
				$(SRCSDIR)vector_view.c \
				$(SRCSDIR)vectors.c

OBJS=$(notdir $(SRCS:.c=.o))

#compilation
CFLAGS		= -Wall -Wextra -Werror
CC 			= clang
MLXCFLAGS 	= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I$(INCSDIR)

#common commands
RM =rm -f

#rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LFTDIR) -L $(MLXDIR) -lft $(MLXCFLAGS)
	mkdir -p objs
	mv $(OBJS) objs/

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -g -c -I ./incs/ $(SRCS)

$(MLX):
	@make -C $(MLXDIR)

$(LIBFT):
	@make -C $(LFTDIR)

bonus: all

re: fclean all

rebonus: fclean bonus

clean:
	@make clean -C $(LFTDIR)
	$(RM) -rf $(OBJS) $(BONUS_OBJS) objs/

fclean: clean
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LFTDIR)
	@make clean -C $(MLXDIR)

.PHONY: clean fclean re rebonus all bonus

# Colors
GREEN	= \033[32;1m
RED		= \033[31;1m
YELLOW	= \033[33;1m
CYAN	= \033[36;1m
RC		= \033[0m
