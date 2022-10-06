# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 09:21:12 by wdonnell          #+#    #+#              #
#    Updated: 2022/10/06 15:03:09 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= lem-in
CC			= clang
#CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -O3
SRC_FILES = main.c read_map.c read_map_extras.c util.c make_graph.c add_rooms_to_graph.c \
hash_map.c linked_list.c check_rooms.c solve.c BFS.c BFS_util.c change_capacity.c \
free_functions.c  free_functions_2.c store_data.c put_ants_on_paths.c compare_paths.c print_ants.c
SRCS_DIR	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_DIR	= ./objects/
OBJS		= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
LIB			= -L libft -lft
INCLUDES	= -I includes -I libft/includes

GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
RED		= "\x1b[31m"
EOC		= "\x1b[0m"

all: $(NAME)
	@echo $(GREEN) "Compiled" $(EOC)
	@make -sC visualizer
	@make -sC map_gen
	@make -sC ant_cop

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIB)
	@echo $(RED) "Compiling..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@make -sC libft
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS_DIR)
#	rm -rf libft/objects/
	rm -f test.map
	rm -f rando.map
#	@make clean -sC visualizer
#	@make clean -sC map_gen
#	@make clean -sC ant_cop

fclean: clean
	rm -f $(NAME)
#	rm -f libft/libft.a
#	@make fclean -sC visualizer
#	@make fclean -sC map_gen
#	@make fclean -sC ant_cop

re: fclean all

