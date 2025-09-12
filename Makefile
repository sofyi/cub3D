NAME = cub3D
SRC = ./pars/pars.c ./pars/get_next_l.c ./pars/helper.c ./pars/helper2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc  $(OBJ) -o $(NAME)
%.o : %.c
	cc -c -Wall -Wextra -Werror $< -o $@
clean:
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re: fclean all
s : all clean