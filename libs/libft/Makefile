# Libft Makefile

#Variables
NAME = libft.a

HEADER_PATH = ./headers/

SRC_PATH 	= ./src

OBJ_PATH 	= ./obj

SRC_FILES    =	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_strdup.c \
				ft_atoi.c ft_strncmp.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_memchr.c ft_strrchr.c \
				ft_strnstr.c  ft_calloc.c  ft_strlcat.c  ft_strlcpy.c  ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c \
				ft_striteri.c  ft_strmapi.c  ft_itoa.c ft_substr.c ft_strjoin.c ft_strchr.c ft_split.c ft_strtrim.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				get_next_line.c get_next_line_utils.c \
				ft_printf.c ft_print_char_str.c ft_print_nbr.c ft_print_ptr.c ft_print_hexa.c

SRCS = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS = ${SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o}

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
GNL_FLAGS = -D BUFFER_SIZE=10

# Compile a library
AR = ar rcs

# Clean
RM = rm -f
RM_DIR = rm -rf

# Rules
all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I./headers -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@$(RM_DIR) $(OBJ_PATH)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
