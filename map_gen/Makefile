# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 14:05:53 by wdonnell          #+#    #+#              #
#    Updated: 2022/09/15 14:06:16 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= map_gen
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
SRCS	= map_gen.c
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