# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 12:16:33 by wdonnell          #+#    #+#              #
#    Updated: 2022/04/15 15:56:04 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= visualizer
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SOURCES		= main.c read_in_info.c read_rooms.c util.c add_room.c
SRCS_DIR	= sources/
SRCS		= $(addprefix	$(SRCS_DIR), $(SOURCES))
OBJS		= $(addprefix	$(OBJS_DIR), $(SOURCES:.c=.o))
OBJS_DIR	= objects/
INCLUDES	= -I includes -I ../libft/includes -I minilibx/
MLX 		= -L minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling ..."
	@$(CC) $(OBJS) $(INCLUDES) -o $(NAME) $(MLX) -L ../libft -lft
	@echo "Compiled"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
	@make -sC ../libft
	@make -sC minilibx
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -f ../libft/objects/*.o
	@make clean -C minilibx/
	@make clean -C ../libft/

fclean: clean 
	@rm -f $(NAME)
	@rm -f ../libft/libft.a
	@make fclean -C ../libft/

re: fclean all

.PHONY: all clean fclean re