# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 12:30:42 by wdonnell          #+#    #+#              #
#    Updated: 2022/04/21 20:40:37 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
#EXTRA_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits -O3
SOURCES		= ft_printf.c get_format_data.c util.c prefix.c modifier.c\
			print_ppc.c print_str.c print_di.c print_binary.c print_octal.c print_unsigned.c \
			print_hex.c print_hex_upper.c print_float.c print_banner.c
		
SRCS_DIR	= sources/
SRCS		= $(addprefix	$(SRCS_DIR), $(SOURCES))
OBJS		= $(addprefix	$(OBJS_DIR), $(SOURCES:.c=.o))
OBJS_DIR	= objects/
INCLUDES	= -I includes -I ..libft/includes

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling ..."
#	make -sC libft
	@cp ..libft/libft.a ./libftprintf.a
	@cp ..libft/includes/libft.h ./includes/
	@ar rc $(NAME) $(OBJS) 
	@@echo "Compiled"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c includes/ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -rf $(OBJS_DIR)
#	@rm -f libft/objects/*.o
#	@make clean -C libft/

fclean: clean 
	@rm -f $(NAME)
#	@rm -f libft/libft.a
#	@make clean -C libft/

re: fclean all

.PHONY: all clean fclean re