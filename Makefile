# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vping <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 12:01:51 by vping             #+#    #+#              #
#    Updated: 2021/03/25 20:42:33 by vping            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
FLAGS	= -Wall -Wextra -Werror
NA		= nasm
NA_FLAG = -f macho64
SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS	= $(SRCS:.s=.o)

%.o:	%.s
	$(NA) $(NA_FLAG) $<

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME) $(OBJS)

re:			fclean $(NAME)

.PHONY:	re clean fclean
