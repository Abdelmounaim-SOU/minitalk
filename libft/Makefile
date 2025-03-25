# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# Directories
SRC_DIR = .
FT_IS_DIR = ft_is
FT_LST_DIR = ft_lst
FT_MEM_DIR = ft_mem
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line
FT_PUT_DIR = ft_put
FT_STR_DIR = ft_str
FT_TO_DIR = ft_to
INCLUDE_DIR = include

# Source files
SRC = $(FT_IS_DIR)/ft_isalnum.c $(FT_IS_DIR)/ft_isalpha.c $(FT_IS_DIR)/ft_isascii.c \
      $(FT_IS_DIR)/ft_isdigit.c $(FT_IS_DIR)/ft_isprint.c \
      $(FT_LST_DIR)/ft_lstadd_back_bonus.c $(FT_LST_DIR)/ft_lstadd_front_bonus.c \
      $(FT_LST_DIR)/ft_lstclear_bonus.c $(FT_LST_DIR)/ft_lstdelone_bonus.c \
      $(FT_LST_DIR)/ft_lstiter_bonus.c $(FT_LST_DIR)/ft_lstlast_bonus.c \
      $(FT_LST_DIR)/ft_lstmap_bonus.c $(FT_LST_DIR)/ft_lstnew_bonus.c \
      $(FT_LST_DIR)/ft_lstsize_bonus.c \
      $(FT_MEM_DIR)/ft_bzero.c $(FT_MEM_DIR)/ft_calloc.c $(FT_MEM_DIR)/ft_memchr.c \
      $(FT_MEM_DIR)/ft_memcmp.c $(FT_MEM_DIR)/ft_memcpy.c $(FT_MEM_DIR)/ft_memmove.c \
      $(FT_MEM_DIR)/ft_memset.c \
      $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putchars.c $(FT_PRINTF_DIR)/ft_putnbrs.c \
      $(FT_PUT_DIR)/ft_putchar_fd.c $(FT_PUT_DIR)/ft_putendl_fd.c $(FT_PUT_DIR)/ft_putnbr_fd.c \
      $(FT_PUT_DIR)/ft_putstr_fd.c \
      $(FT_STR_DIR)/ft_split.c $(FT_STR_DIR)/ft_strchr.c $(FT_STR_DIR)/ft_strdup.c \
      $(FT_STR_DIR)/ft_striteri.c $(FT_STR_DIR)/ft_strjoin.c $(FT_STR_DIR)/ft_strlcat.c \
      $(FT_STR_DIR)/ft_strlcpy.c $(FT_STR_DIR)/ft_strlen.c $(FT_STR_DIR)/ft_strmapi.c \
      $(FT_STR_DIR)/ft_strncmp.c $(FT_STR_DIR)/ft_strnstr.c $(FT_STR_DIR)/ft_strrchr.c \
      $(FT_STR_DIR)/ft_strtrim.c $(FT_STR_DIR)/ft_substr.c \
      $(FT_TO_DIR)/ft_atoi.c $(FT_TO_DIR)/ft_itoa.c $(FT_TO_DIR)/ft_tolower.c \
      $(FT_TO_DIR)/ft_toupper.c $(GET_NEXT_LINE_DIR)/get_next_line.c $(GET_NEXT_LINE_DIR)/get_next_line_utils.c

# Bonus source files
BSRC = $(FT_LST_DIR)/ft_lstadd_back_bonus.c $(FT_LST_DIR)/ft_lstadd_front_bonus.c \
       $(FT_LST_DIR)/ft_lstclear_bonus.c $(FT_LST_DIR)/ft_lstdelone_bonus.c \
       $(FT_LST_DIR)/ft_lstiter_bonus.c $(FT_LST_DIR)/ft_lstlast_bonus.c \
       $(FT_LST_DIR)/ft_lstmap_bonus.c $(FT_LST_DIR)/ft_lstnew_bonus.c \
       $(FT_LST_DIR)/ft_lstsize_bonus.c

# Object files
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

# Include directories
INCLUDES = -I$(INCLUDE_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(BOBJ)
	ar -rcs $(NAME) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
