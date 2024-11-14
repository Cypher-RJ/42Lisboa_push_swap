# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:11:47 by rcesar-d          #+#    #+#              #
#    Updated: 2024/11/14 09:16:03 by rcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 14:11:47 by rcesar-d          #+#    #+#              #
#    Updated: 2024/11/07 14:57:25 by rcesar-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

INC	=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

CC	=	cc
CFLAGS	=	-Wall -Werror -Wextra -g -I$(INC)
RM	=	rm -f

COMMANDS_DIR	=	$(SRC_DIR)push.c \
			$(SRC_DIR)r_rotate.c \
			$(SRC_DIR)rotate.c \
			$(SRC_DIR)sort_u.c \
			$(SRC_DIR)sort.c \
			$(SRC_DIR)sort_three.c \
			$(SRC_DIR)swap.c

PUSH_SWAP_DIR	=	$(SRC_DIR)errors.c \
			$(SRC_DIR)init_ab.c \
			$(SRC_DIR)init_ba.c \
			$(SRC_DIR)init_s.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)funcions.c

MAIN_DIR		=	$(SRC_DIR)main.c

SRCS	=	$(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(MAIN_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(NAME):	$(OBJS)
		@echo "Make .o and push_swap."
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
		@$(RM) -r $(OBJ_DIR)
		@echo "Clean .o files."

fclean:		clean
		@$(RM) $(NAME)
		@echo "Clean executable/s."

re:		fclean all

.PHONY:		all clean fclean re