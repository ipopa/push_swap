#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipopa <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/13 14:40:58 by ipopa             #+#    #+#              #
#    Updated: 2016/05/13 14:40:58 by ipopa            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
FLAGS = -g -Wall -Werror -Wextra
IDIR = includes/
SDIR = srcs/
ODIR = objects/
SRC = $(shell find $(SDIR) -type f | grep -e \.c$$)
LIB = libft/
OBJ = $(SRC:.c=.o)
LFILES = $(shell find $(LIB) -type f | grep -e \.c$$)
LOBJ = $(LFILES:.c=.o)

all : $(NAME)

$(NAME): $(LOBJ) $(OBJ)
		@echo -n 'Push_swap:  Creating $(NAME) done...			'
		@gcc -o $(NAME) $(OBJ) -L $(LIB) -lft -I $(IDIR)
		@echo "\033[32mOK\033[0m"

clean :
		@make clean -C libft
		@echo -n 'Push_swap:  Removing objects...				'
		@rm -f $(OBJ)
		@echo "\033[32mOK\033[0m"

$(LIB)%.o:	$(LIB)%.c
					@make -C $(LIB)
%.o:%.c
		@echo -n 'Push_swap:  Compiling done...				'
		@gcc -c $< -o $@ -I $(IDIR)
		@echo "\033[32mOK\033[0m"

fclean:	clean
		@echo -n 'libft:      Removing libft.a...				'
		@rm -f $(LIB)libft.a
		@echo "\033[32mOK\033[0m"
		@echo -n 'Push_swap:  Removing push_swap...			'
		@rm -f $(NAME)
		@echo "\033[32mOK\033[0m"

re: fclean all
