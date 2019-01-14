#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 15:03:31 by myarovoy          #+#    #+#              #
#    Updated: 2017/11/22 15:03:32 by myarovoy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	main.c \
				file_validation.c \
				tetromino_validation.c \
				number_of_tetros.c \
				split_tetros.c \
				place_top_left.c \
				fill_field.c \
				back_track_tetro.c \
				draw_tetro.c \
				is_there_enough_space.c \
				empty_space.c 

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re