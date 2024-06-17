# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 19:03:47 by pmolzer           #+#    #+#              #
#    Updated: 2024/06/17 13:44:02 by hzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard sources/*.c)

OBJS = ${SRCS:.c=.o}

CC = cc 
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -lreadline -lhistory

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a 
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC		=	-I ./includes/\
			-I $(LIBFT_PATH)\

RM = rm -rf

all: $(LIBFT)$(NAME)

$(LIBFT):
	-$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS)                 
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) -o $(NAME) $(INC)

clean:
		@$(RM) $(OBJS) $(LIBFT_PATH)/*.o

fclean: clean
		@${RM} ${NAME} $(LIBFT)

re: fclean all

.PHONY: all clean re
