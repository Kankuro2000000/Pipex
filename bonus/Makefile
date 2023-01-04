# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtasia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 10:19:59 by vtasia            #+#    #+#              #
#    Updated: 2022/04/07 10:20:09 by vtasia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

HEADER		=	pipex_bonus.h
SRC			=	ft_split.c	gnl.c	lib_function_vol2.c	lib_function.c	pipex_bonus.c \
				pipex_function_bonus.c	pipex_parsing_function_bonus.c
				

OBJ_DIR	=	obj
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

RM_DIR		=	rm -rf
RM_FILE		=	rm -f

INCLUDES	= 	-I .

${NAME}:	${OBJ}
			$(CC) -o $(NAME) $(OBJ) $(FLAGS)
						
$(OBJ)		:	| $(OBJ_DIR)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			
$(OBJ_DIR)/%.o :	%.c $(HEADER) Makefile
					${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<
			
all:	$(NAME)

clean:
		@${RM_DIR} ${OBJ_DIR}
		
fclean:	clean
		@${RM_FILE} $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re
