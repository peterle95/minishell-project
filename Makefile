# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 19:03:47 by pmolzer           #+#    #+#              #
#    Updated: 2024/06/15 19:03:47 by pmolzer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = $(wildcard sources/*.c)

OBJS = ${SRCS: .c=.o}

CC = cc 
CFLAGS = -Wall -Wextra -Werror
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
		@$(RM) $(OBJS)

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean re