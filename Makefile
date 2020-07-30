NAME = prog

SRC = main.c

S_DIR = src
O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))
HEAD = test.h
H_DIR = includes
GCC = gcc -Wall -Wextra -Werror
DEPS = $(patsubst %,$(H_DIR)/%,$(HEAD))
INC = -I $(H_DIR) -I $(SDL_INC_DIR)

#L_SDL = `./SDL2-2.0.12/sdl2-config --cflags --libs`
L_SDL = `$(SDL_DIR)/sdl2-config --cflags --libs`
SDL_DIR = SDL2-2.0.12
SDL_INC_DIR = SDL2-2.0.12/include
SDL_TAR = SDL2-2.0.12.tar.gz

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $@ $^ $(L_SDL)

$(O_DIR)/%.o : $(S_DIR)/%.c $(DEPS)
	$(GCC) -o $@ -c $< $(INC)

$(OBJ): | $(O_DIR)

clean:
	@rm -rf $(O_DIR)

fclean:
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@rm -rf $(SDL_DIR)

re: fclean all

$(O_DIR): | $(SDL_DIR)
	mkdir $(O_DIR)

$(SDL_DIR):
	tar -xvf $(SDL_TAR)
	cd $(SDL_DIR) && ./configure --prefix=`pwd`/lib
	make -C $(SDL_DIR)
	make -C $(SDL_DIR) install
