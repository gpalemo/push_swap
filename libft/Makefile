# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 18:13:41 by cmauley           #+#    #+#              #
#    Updated: 2026/02/02 21:40:53 by cmauley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Dossiers #
SRC_DIR		=		src/
OBJ_DIR		=		obj/

# fichiers source .c de la lib #
SRCS		=		$(addprefix $(SRC_DIR), ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
					ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
					ft_toupper.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c)

# changements des .c en .o #
OBJS		=		$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# fichiers bonus #
BONUS_SRCS	=		$(addprefix $(SRC_DIR), ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c)

# changements des fichiers bonus .c en .o #
BONUS_OBJS	=		$(addprefix $(OBJ_DIR), $(notdir $(BONUS_SRCS:.c=.o)))

# commandes #
CC			=		gcc
RM			=		rm -f
AR 			=		ar rcs
CFLAGS		=		-Wall -Wextra -Werror -I. -I$(SRC_DIR)

# Nom de la lib #
NAME		=		libft.a

# ========== REGLES ======= #

# Regle principale : "all" executee par defaut #
all:				$(NAME)

# Regle pour construire la librairie #
$(NAME):			$(OBJ_DIR) $(OBJS)
					$(AR) $(NAME) $(OBJS)

# Créer le dossier obj s'il n'existe pas #
$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

# Règle générique pour compiler les fichiers #
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					$(CC) $(CFLAGS) -c $< -o $@

# Ajout des bonus #
bonus:				$(OBJ_DIR) $(OBJS) $(BONUS_OBJS)
					$(AR) $(NAME) $(BONUS_OBJS)

# Supprimer les fichiers objets (.o) #
clean:
					$(RM) -r $(OBJ_DIR)

# Supprimer tout (objets + librairie) #
fclean:				clean
					$(RM) $(NAME)

# tout recompiler #
re:					fclean all

# cibles pour eviter les conflits de noms #
.PHONY:				all clean fclean re bonus




