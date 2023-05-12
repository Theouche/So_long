# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlorne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:46:06 by tlorne            #+#    #+#              #
#    Updated: 2023/05/11 15:55:51 by tlorne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c utils.c get_map.c \
		ft_check_map.c ft_check_path.c \
		ft_move.c create_map.c put_image.c ft_footer.c \
		ft_free.c ft_end.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJ}
	@make -C libft
	@make -C libmlx
	gcc ${CFLAGS} ${OBJ} libmlx/libmlx.a -lXext -lX11 -lm -lbsd libft/libft.a -o ${NAME}

clean :
		@make clean -C libft
		@make clean -C libmlx
		rm -f ${OBJ} ${OBJ_BONUS} ${OBJ2}

fclean : clean
		@make fclean -C libft
		rm -f ${NAME} ${NAME2}

re : fclean all
