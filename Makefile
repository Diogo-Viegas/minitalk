# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 08:55:23 by dviegas           #+#    #+#              #
#    Updated: 2025/06/18 09:00:58 by dviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
CLIENT = client
SERVER = server
HEADER = ./includes/minitalk.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c 

CC = cc
RM = rm -rf

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3 -O3

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT)  $(HEADER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)  $(HEADER)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	
clean: 
	rm -rf $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER)
	make clean -C $(LIBFT_DIR)

	
fclean: clean 
	rm -f $(CLIENT)
	rm -f $(SERVER)
	@rm -f $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

