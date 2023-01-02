NAME = typing

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	typing.c \
		get-next-line/get_next_line.c get-next-line/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	@make -C ./lib
	@$(CC) $(CFLAGS) $(OBJ) lib/libft.a -o $(NAME)
	@clear
	@echo "\033[0;31m run ./typing"

clean :
	@make clean -C ./lib
	@-rm -rf *.o ./get_next_line/*.o
fclean : clean
	@make fclean -C ./lib
	@-rm -rf $(NAME)

re : fclean all