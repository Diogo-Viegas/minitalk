# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 14:48:46 by dviegas           #+#    #+#              #
#    Updated: 2025/05/26 11:06:33 by dviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTF_DIR = ft_printf
AR = ar rcs
CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c \
	   ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c \
	   ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	   ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	   ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCS_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c\
			 ft_lstlast.c ft_lstnew.c ft_lstmap.c ft_lstsize.c
			 
PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/,\
			ft_printf.c \
			ft_printf_utils.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			ft_print_unsigned.c \
			)
ALL_SRCS = $(SRCS) $(PRINTF_SRCS)
OBJS = ${ALL_SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME} ${OBJS_B}
	${AR} ${NAME} ${OBJS_B}
	touch ${NAME}
clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
	
re : fclean all

.PHONY : all clean fclean re