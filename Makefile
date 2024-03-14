# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:40:23 by bda-mota          #+#    #+#              #
#    Updated: 2024/03/14 12:39:24 by bda-mota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= push_swap
CFLAGS		:= -Wextra -Wall -Werror -g3 -O0

# LIBRARIES_PATH
LIBFT_PATH = ./libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH 	:= objects

# SOURCES
CFILES		:= main.c utils.c

SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

HEADERS		:= -I ./includes
HEADER_FILE := includes/push_swap.h

MAKEFLAGS += --silent

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)PUSH SWAP$(WHITE)] has been compiled!  "
	@echo "$(GREEN)-------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE) Objects - PUSH SWAP - were cleaned!"
	@echo "$(RED)-----------------------------------"

fclean: clean
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(RED)-----------------------------------"
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE) ✨ Cleaning - PUSH SWAP - complete! ✨"
	@echo "$(RED)---------------------------------------"

re: fclean all

.PHONY: all, clean, fclean, re
