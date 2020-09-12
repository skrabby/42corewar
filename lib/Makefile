# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 11:23:44 by skrabby           #+#    #+#              #
#    Updated: 2020/09/12 15:52:24 by skrabby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF_DIR = ./ft_printf/%.c
LIBFT_DIR = ./libft/%.c

PRINTF_SRCS = ft_printf \
	   flags \
	   type_checker \
	   adapt_charflags \
	   adapt_gridflag \
	   adapt_nbflags \
	   ll_itoa_base_func \
	   ll_itoa_base \
	   llu_itoa_base \
	   finalstr \
	   color \
	   ld_handler \
	   str_multiplier \
	   return_result \
	   new_functions \
	   type_checker_func \
	   clear_create_flags \
	   grid_types \
	   ld_optimize \
	   ld_round \
	   ld_precision \
	   egflag_handler \
	   check_star \

LIB_SRCS = ft_memset \
	   ft_bzero \
	   ft_memcpy \
	   ft_memccpy \
	   ft_memmove \
	   ft_memchr \
	   ft_memcmp \
	   ft_strlen \
	   ft_strdup \
	   ft_strcpy \
	   ft_strncpy \
	   ft_strcat \
	   ft_strncat \
	   ft_strlcat \
	   ft_strchr \
	   ft_strrchr \
	   ft_strstr \
	   ft_strnstr \
	   ft_strcmp \
	   ft_strncmp \
	   ft_atoi \
	   ft_isalpha \
	   ft_isdigit \
	   ft_isalnum \
	   ft_isascii \
	   ft_isprint \
	   ft_toupper \
	   ft_tolower \
	   ft_memalloc \
	   ft_memdel \
	   ft_strnew \
	   ft_strdel \
	   ft_strclr \
	   ft_striter \
	   ft_striteri \
	   ft_strmap \
	   ft_strmapi \
	   ft_strequ \
	   ft_strnequ \
	   ft_strsub \
	   ft_strjoin \
	   ft_strtrim \
	   ft_strsplit \
	   ft_putchar \
	   ft_putstr \
	   ft_putnbr \
	   ft_itoa \
	   ft_putendl \
	   ft_putchar_fd \
	   ft_putstr_fd \
	   ft_putendl_fd \
	   ft_putnbr_fd \
	   ft_lstnew \
	   ft_lstdel \
	   ft_lstdelone \
	   ft_lstadd \
	   ft_lstiter \
	   ft_lstmap \
	   ft_strndup \
	   ft_strreverse \
	   ft_lstcount \
	   ft_lstaddlast \
	   ft_lstreverse \
	   ft_module \
	   ft_nblen \
	   ft_strempty_symb \
	   ft_negativezero \
	   ft_putstr_null \
	   ft_atoi32 \
	   get_next_line \

OBJ =	$(addprefix obj/, $(addsuffix .o, $(PRINTF_SRCS))) \
		$(addprefix obj/, $(addsuffix .o, $(LIB_SRCS)))

LIB_HEADER = ./srcs/libft/libft.h
PRINTF_HEADER = ./srcs/ft_printf/ft_printf.h

all: $(NAME)

obj/%.o: $(LIBFT_DIR)
	@gcc -Wall -Wextra -Werror -c $< -o $@

obj/%.o: $(PRINTF_DIR)
	@gcc -Wall -Wextra -Werror -c $< -o $@
	
$(NAME): obj $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@tput setaf 2; tput bold; echo "$(NAME) was created"
	@tput setaf 7;

obj:
	@mkdir obj

clean:
	@rm -rf obj
	@tput setaf 1; tput bold; echo "objects were deleted"
	@tput setaf 7;

fclean: clean
	@rm -f $(NAME)
	@tput setaf 1; tput bold; echo "$(NAME) was deleted"
	@tput setaf 7;

re: fclean all

.PHONY: all clean fclean re
