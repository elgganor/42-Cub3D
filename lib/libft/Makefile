# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouabeh <mrouabeh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 18:06:58 by mrouabeh          #+#    #+#              #
#    Updated: 2020/03/09 08:22:17 by mrouabeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

DISPLAY=display/ft_putnbr.c \
	display/ft_putchar_fd.c \
	display/ft_putendl_fd.c \
	display/ft_putnbr_fd.c \
	display/ft_putstr_fd.c \
	display/ft_putchar.c \
	display/ft_putstr.c \
	display/ft_putnbrn.c \
	display/ft_putstrn.c
CHECKER=checker/ft_islower.c \
	checker/ft_isupper.c \
	checker/ft_isalnum.c \
	checker/ft_isalpha.c \
	checker/ft_isascii.c \
	checker/ft_isdigit.c \
	checker/ft_isprint.c
CONVERT=convert/ft_tolower.c \
	convert/ft_toupper.c \
	convert/ft_ltohex.c \
	convert/ft_itohex.c \
	convert/ft_strtoupper.c \
	convert/ft_itou.c \
	convert/ft_ltoa.c \
	convert/ft_abs.c \
	convert/ft_atoi.c \
	convert/ft_itoa.c \
	convert/ft_atol.c
MEMORY=memory/ft_bzero.c \
	memory/ft_calloc.c \
	memory/ft_memccpy.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memset.c
STRING=string/ft_split.c \
	string/ft_strchr.c \
	string/ft_strdup.c \
	string/ft_strjoin.c \
	string/ft_strlcat.c \
	string/ft_strlcpy.c \
	string/ft_strlen.c \
	string/ft_strmapi.c \
	string/ft_strncmp.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strtrim.c \
	string/ft_substr.c \
	string/ft_strcmp.c
LINKED_LIST=linked_list/ft_lstadd_front_bonus.c \
	linked_list/ft_lstadd_back_bonus.c \
	linked_list/ft_lstdelone_bonus.c \
	linked_list/ft_lstclear_bonus.c \
	linked_list/ft_lstiter_bonus.c \
	linked_list/ft_lstmap_bonus.c \
	linked_list/ft_lstlast_bonus.c \
	linked_list/ft_lstnew_bonus.c \
	linked_list/ft_lstsize_bonus.c
GNL=get_next_line/get_next_line.c

SRC_PATH=./src/
SRC=$(DISPLAY) $(CHECKER) $(CONVERT) $(MEMORY) $(STRING) $(GNL) $(LINKED_LIST)
SRCS=$(addprefix $(SRC_PATH), $(SRC))

OBJ= $(SRCS:.c=.o)

FLAGS=-Wall -Wextra -Werror
INC=-I./inc



all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re
