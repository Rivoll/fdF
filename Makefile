NAME = fdf
CC = gcc
SRC = main.c\
	  ft_fdf.c\
	  ft_event.c\
	  ft_solve.c\
	  ft_read.c

SALE = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a 
	$(CC) $(OBJ) libft/libft.a $(SALE) -o $(NAME)

libft/libft.a :
	make -C libft

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $< 

.Phony: all clean fclean 