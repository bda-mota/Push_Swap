# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:40:23 by bda-mota          #+#    #+#              #
#    Updated: 2024/04/04 16:17:33 by bda-mota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= push_swap
NAME_BONUS	:= checker
CFLAGS		:= -Wextra -Wall -Werror -g3 -O3

# LIBRARIES_PATH
LIBFT_PATH = ./libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH 	:= objects
BONUS_PATH	:= sources_bonus
OBONUS_PATH	:= objects_bonus

# SOURCES
CFILES		:= main.c utils.c linked_list.c swap.c rotate.c reverse_rotate.c push.c linked_list_aux.c \
			push_swap.c index.c position.c cost.c init.c operations.c update.c

BFILES		:= main_bonus.c linked_list_bonus.c swap_bonus.c rotate_bonus.c reverse_rotate_bonus.c \
			push_bonus.c linked_list_aux_bonus.c init_bonus.c utils_bonus.c

SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))
BONUS		:= $(addprefix $(BONUS_PATH)/, $(BFILES))
OBJ_BONUS	:= $(addprefix $(OBONUS_PATH)/, $(BFILES:%.c=%.o))

HEADERS		:= -I ./includes
HEADER_FILE := includes/push_swap.h includes/push_swap_bonus.h

MAKEFLAGS += --silent

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: $(OBJ_PATH) $(NAME)

bonus: libft $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEADER_FILE) | $(OBONUS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBONUS_PATH):
	@mkdir -p $(OBONUS_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)PUSH SWAP$(WHITE)] has been compiled!  "
	@echo "$(GREEN)-------------------------------------------"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBS_MLX) $(LIBFT) $(INCLUDES) -o $(NAME_BONUS)
	@echo "$(GREEN)----------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)PUSH SWAP BONUS$(WHITE)] has been compiled!  "
	@echo "$(GREEN)----------------------------------------------"
	
clean:
	@rm -rf $(OBJS) $(OBJ_BONUS) 
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE) Objects - PUSH SWAP - were cleaned!"
	@echo "$(RED)-----------------------------------"

fclean: clean
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(RED)-----------------------------------"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE) ✨ Cleaning - PUSH SWAP - complete! ✨"
	@echo "$(RED)---------------------------------------"

re: fclean all bonus

.PHONY: all, clean, fclean, re
