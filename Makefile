NAME = prog

SRC = main.c

S_DIR = src
O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))
HEAD = test.h
H_DIR = includes
GCC = gcc -Wall -Wextra -Werror
DEPS = $(patsubst %,$(H_DIR)/%,$(HEAD))

L_SDL = `libraries/libui/SDL2-2.0.12/sdl2-config --cflags --libs`

INC = -I libraries/libft/includes

LIBS = libraries
LIBFT = $(LIBS)/libft.a
LIBUI = $(LIBS)/libui.a

all: $(LIBS) $(NAME)

$(NAME): $(OBJ) 
	$(GCC) -o $@ $^ -I $(H_DIR) $(LIBUI) $(LIBFT) $(L_SDL)

$(O_DIR)/%.o : $(S_DIR)/%.c $(DEPS)
	$(GCC) -o $@ -c $< -I $(H_DIR) $(INC)

$(OBJ): | $(O_DIR)

clean:
	@rm -rf $(O_DIR)
	make clean -C $(LIBS)/libft
	make clean -C $(LIBS)/libui

fclean: clean
	@rm -rf $(NAME)
	make fclean -C $(LIBS)/libft
	make fclean -C $(LIBS)/libui

re: fclean all

$(O_DIR):
	mkdir $(O_DIR)

$(LIBS): | $(LIBFT) $(LIBUI)

$(LIBFT):
	make -C $(LIBS)/libft

$(LIBUI):
	make -C $(LIBS)/libui