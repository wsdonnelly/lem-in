# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 09:21:12 by wdonnell          #+#    #+#              #
#    Updated: 2022/04/23 11:10:59 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
#EXTRA_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits -O3
SRC_FILES	= main.c read_map.c util.c graph.c hash_map.c linked_list.c 
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

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIB)
	@echo $(RED) "Compiling..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@make -sC libft
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -rf libft/objects/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

