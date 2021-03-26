# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vping <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 12:01:51 by vping             #+#    #+#              #
#    Updated: 2021/03/26 18:02:30 by vping            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
FLAGS	= -Wall -Wextra -Werror
NA		= nasm
NA_FLAG = -f macho64
SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_B	= ft_list_size_bonus.s ft_list_push_front_bonus.s
OBJS	= $(SRCS:.s=.o)
OBJS_B	= $(SRCS:.s=.o) $(SRCS_B:.s=.o)

%.o:	%.s
	$(NA) $(NA_FLAG) $<

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_B)

fclean:		clean
	rm -rf $(NAME) $(OBJS) $(OBJS_B)
	rm -rf a.out

re:			fclean $(NAME)

bonus: $(OBJS_B)
	ar rc $(NAME) $(OBJS_B)
	ranlib $(NAME)

.PHONY:	re clean fclean bonus
