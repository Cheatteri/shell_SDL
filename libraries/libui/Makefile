#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 19:05:42 by jhakala           #+#    #+#              #
#    Updated: 2020/08/01 21:35:45 by jhakala          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libui.a

GCC = gcc -Wall -Wextra -Werror
DEPS = $(patsubst %,$(H_DIR)/%,$(HEAD))

S_DIR = src
SRC = draw_line.c

O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))

H_DIR = includes
HEAD = libui.h structs.h

LFTH = ../libft/includes

SDL_TAR = SDL2-2.0.12.tar.gz
SDL_DIR = SDL2-2.0.12
SDL_INC_DIR = SDL2-2.0.12/include

INC = -I $(H_DIR) -I $(SDL_INC_DIR) -I $(LFTH)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@
	mv $(NAME) ../
	@echo "libui.a \033[1;32m[OK]\033[0m"

$(O_DIR)/%.o : $(S_DIR)/%.c $(DEPS)
	$(GCC) -o $@ -c $< $(INC)

clean:
	rm -rf $(O_DIR)

fclean:
	rm -rf $(O_DIR)
	rm -rf ../$(NAME)
	bash del.sh

delete:
	rm -rf $(SDL_DIR)

re: fclean all

$(OBJ): | $(O_DIR)

$(O_DIR): | $(SDL_DIR)
	mkdir $(O_DIR)

$(SDL_DIR):
	tar -xvf $(SDL_TAR)
	cd $(SDL_DIR) && ./configure --prefix=`pwd`/lib
	make -C $(SDL_DIR)
	make -C $(SDL_DIR) install