# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 08:55:23 by dviegas           #+#    #+#              #
#    Updated: 2025/06/18 16:37:55 by dviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
HEADER = ./includes/minitalk.h
HEADER_BONUS = ./includes/minitalk_bonus.h
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c 
SRC_CLIENT_BONUS = bonus/client_bonus.c bonus/utils_bonus.c
SRC_SERVER_BONUS = bonus/server_bonus.c

CC = cc
RM = rm -rf

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3 -O3

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFT)  $(HEADER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)  $(HEADER)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)  $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)  $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)


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

