NAME 	=	so_long
FLAGS 	=	-Werror -Wextra -Wall
LIBS =  -lmlx -framework OpenGL -framework AppKit

SRC 	=	so_long.c moving.c dop_fun.c ft_split.c read_map.c check_map.c
OBJ		=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(SRC) -o $(NAME) $(LIBS) -I

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re