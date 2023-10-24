# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrimonte <rrimonte@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:50:55 by rrimonte          #+#    #+#              #
#    Updated: 2023/09/04 15:18:00 by rrimonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
LIBS_TARGET		:= 	libft/libft.a
HEADERS			=	pipex_bonus/pipex_bonus.h
SRCS			=	get_next_line/get_next_line_bonus.c \
					get_next_line/get_next_line_utils_bonus.c \
					pipex_bonus/ft_files_bonus.c \
					pipex_bonus/ft_lst_bonus.c \
					pipex_bonus/ft_parse_bonus.c \
					pipex_bonus/ft_pipes_bonus.c \
					pipex_bonus/main_bonus.c

OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
GET_NEXT_LINE_FOLDER	=	get_next_line/
LIBFT_FOLDER	=	libft/
LIBFT_NAME		=	libft.a
LIBS			=	$(LIBFT_FOLDER)$(LIBFT_NAME)
AR				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
RM				=	rm -rf

$(NAME): $(LIBS) $(OBJS) $(HEADERS)
		$(CC)  $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) 
$(LIBS_TARGET):
	$(MAKE) -C $(LIBFT_FOLDER)
all: $(NAME)
clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	$(RM) $(NAME)
re: fclean all
