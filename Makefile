# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 19:03:47 by pmolzer           #+#    #+#              #
#    Updated: 2024/06/20 12:08:10 by hzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard sources/*.c)

OBJS = ${SRCS:.c=.o}

CC = cc 
CFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -lreadline -lhistory
ADSAN = -fsanitize=address
INC		=	-Iincludes\
			-I$(LIBFT_PATH)\

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a 
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@if [ ! -f "$(LIBFT)" ]; then \
		$(MAKE) -C $(LIBFT_PATH); \
	fi

clean:
		@$(RM) $(OBJS) $(LIBFT_PATH)/*.o

fclean: clean
		@${RM} ${NAME} $(LIBFT)

re: fclean all

.PHONY: all clean re
