NAME = wolf3d

FLAGS = -c -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = head.h

SRC = ./SRC/main.c ./SRC/keyhooks.c ./SRC/draw.c ./SRC/ray.c ./SRC/read.c ./SRC/initialise_stuff.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)	
	make -C libft/
	gcc -o $(NAME) $(BINS) -L. libft/libft.a  $(MLX)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o  $@ $<

clean:
	 /bin/rm -f $(BINS)
	 

fclean: clean
	/bin/rm -f $(NAME)
	

re: fclean all

all_clean: all clean
