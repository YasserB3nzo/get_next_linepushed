# Variables
NAME = libget.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = get_next_line.c f_work.c get_help.c

# Object files
OBJ = $(SRC:.c=.o) 

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean