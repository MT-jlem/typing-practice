NAME = typing

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	typing.c \
		get-next-line/get_next_line.c get-next-line/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	make -C ./libFT
	$(CC) $(CFLAGS) $(OBJ) libFT/libft.a -o $(NAME)

clean :
	@make clean -C ./libFT
	@-rm -rf *.o ./get_next_line/*.o
fclean : clean
	@make fclean -C ./libFT
	@-rm -rf $(NAME)

re : fclean all