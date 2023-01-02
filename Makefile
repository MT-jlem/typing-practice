NAME = typing

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	typing.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean :
	@make clean -C ./libft
	@-rm -rf *.o ./get_next_line/*.o
fclean : clean
	@make fclean -C ./libft
	@-rm -rf $(NAME)

re : fclean all