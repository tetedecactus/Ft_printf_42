# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 10:02:49 by olabrecq          #+#    #+#              #
#    Updated: 2021/07/22 13:08:33 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS = ft_printf.c \
		check_conversion.c \
		print_outils.c \
		print_outils2.c \
		print_till_sign.c \

OBJS 	= ${SRCS:.c=.o}

HEADER	= ft_printf.h

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:
					${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o} 

all: 		${NAME}

$(NAME):	${OBJS}
					ar rc ${NAME} ${OBJS}
clean:
					rm -f ${OBJS}

fclean: 	clean
					rm -f $(NAME)
re:			fclean all 

.PHONY: all clean fclean re