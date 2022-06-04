# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 10:23:27 by wdonnell          #+#    #+#              #
#    Updated: 2022/06/04 15:12:55 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
#FLAGS = -Wall -O3
SRCS= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c \
ft_num_digits.c ft_strset.c ft_putnbr_base.c ft_putstr_len.c \
ft_strchr_i.c ft_word_count.c ft_abs.c ft_strjoin_inplace.c \
ft_printf.c pf_get_format_data.c pf_modifier.c pf_prefix.c pf_print_banner.c \
pf_print_binary.c pf_print_di.c pf_print_float.c pf_print_hex.c pf_print_octal.c \
pf_print_ppc.c pf_print_unsigned.c pf_print_hex_upper.c pf_print_str.c pf_util.c

SRCS_DIR = ./sources/
OBJS = $(addprefix	$(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = ./objects/
INCLUDES =  -I includes

BLUE	= "\x1b[34m"

all: $(NAME)
	
$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo $(BLUE) "Compiling libft..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
	

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re