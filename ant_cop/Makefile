# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:06:38 by wdonnell          #+#    #+#              #
#    Updated: 2022/10/11 13:36:18 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ant_cop
CC 		= gcc
#CFLAGS	= -Wall -Wextra -Werror -O3
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
SRCS	= ant_cop.c functions.c ft_strsplit.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all