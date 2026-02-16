# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 17:37:03 by cmauley           #+#    #+#              #
#    Updated: 2026/02/16 18:01:31 by cmauley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==================== VARIABLES ====================

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

# Dossiers
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIBFT_DIR	=	libft/

# Fichiers sources
SRCS		=	$(SRC_DIR)push_swap.c \
				$(SRC_DIR)algo/five_or_less.c \
				$(SRC_DIR)algo/index.c \
				$(SRC_DIR)algo/more_than_five.c \
				$(SRC_DIR)algo/sort.c \
				$(SRC_DIR)instructions/print_output.c \
				$(SRC_DIR)instructions/push_action.c \
				$(SRC_DIR)instructions/rotate_action.c \
				$(SRC_DIR)instructions/swap_action.c \
				$(SRC_DIR)parsing/is_a_sorted.c \
				$(SRC_DIR)parsing/parse.c \
				$(SRC_DIR)utils/free.c \
				$(SRC_DIR)utils/how_many_int.c

# Objets
OBJS		=	$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# Libft
LIBFT		=	$(LIBFT_DIR)libft.a

# ==================== REGLES ====================

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -I $(LIBFT_DIR)include -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)algo/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -I $(LIBFT_DIR)include -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)instructions/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -I $(LIBFT_DIR)include -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)parsing/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -I $(LIBFT_DIR)include -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)utils/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -I $(LIBFT_DIR)include -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re