# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 14:11:55 by nfurlani          #+#    #+#              #
#    Updated: 2023/10/10 19:24:56 by nfurlani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	= 	checker

BONUS_PATH	=	./Checker_PushSwap/

SRC			=	double_rules.c print_moves.c sort.c utils_lst.c count_moves.c min_moves.c push.c rules.c utils.c check.c

SRC_BONUS	=	$(BONUS_PATH)bonus.c $(BONUS_PATH)double_rules_bonus.c $(BONUS_PATH)rules_bonus.c $(BONUS_PATH)utils_bonus.c $(BONUS_PATH)utils_lst_bonus.c

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean all


bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

.PHONY:		all clean fclean re