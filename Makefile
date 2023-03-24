# Minitalk Makefile
NAME = minitalk
SERVER = server
CLIENT = client

#Paths
SRC_PATH = ./src
OBJ_PATH = ./obj

#Headers minitalk
HEADER = ./headers

#Files
SERVER_FILES = server.c server_utils.c
CLIENT_FILES = client.c client_utils.c validate_cli.c 

#all files .c with the path
SERVER_SRC = $(addprefix $(SRC_PATH)/, $(SERVER_FILES))
CLIENT_SRC = $(addprefix $(SRC_PATH)/, $(CLIENT_FILES))

#all files .o 
SERVER_OBJ = $(SERVER_SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

#My libft.a
LIBFT_PATH = ./libs/libft
LIBFT_HEADER = LIBFT_PATH/src/libft.h
LIBFT = LIBFT_PATH/libft.a

# Compilation
CC = cc
DEBUG = -g3
CFLAGS = -Wall -Wextra -Werror $(DEBUG)
LIB_FLAGS = -lft

# Clean
RM 		= rm -f
RM_DIR	= rm -rf

#Rules
all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)
	@echo "\033[00;32mclient and server created\033[00;37m"

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@$(CC) $(SERVER_OBJ) -L$(LIBFT_PATH) $(LIB_FLAGS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@$(CC) $(CLIENT_OBJ) -L$(LIBFT_PATH) $(LIB_FLAGS) -o $(CLIENT)

# gerar os arquivos .o
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "\033[00;32mlibft.a created\033[00;37m"

clean:
	@$(RM_DIR) $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "\033[00;35mAll object files removed\033[00;37m"

fclean: clean
	@$(RM) $(NAME) $(SERVER) $(CLIENT)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[00;35mClean all\033[00;37m"

re: fclean all

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./server

norma: 
	@norminette ./src ./headers

.PHONY: all clean fclean re
