CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

SRCS =  ft_memcpy.c   ft_strdup.c    ft_putstr_fd.c  ft_strrchr.c  ft_tolower.c \
         ft_bzero.c    ft_isalpha.c   ft_isdigit.c   ft_atoi.c     ft_memchr.c  \
         ft_putchar_fd.c ft_split.c    ft_strlcat.c   ft_strmapi.c  ft_strtrim.c \
         ft_itoa.c     ft_isalnum.c   ft_isascii.c   ft_memmove.c  ft_putendl_fd.c \
         ft_striteri.c  ft_strlcpy.c   ft_strncmp.c   ft_strjoin.c  ft_strlen.c   \
         ft_strnstr.c   ft_substr.c ft_strchr.c ft_memset.c ft_calloc.c ft_isprint.c \
		 ft_memcmp.c	ft_toupper.c	ft_putnbr_fd.c

SRCSB = ft_lstadd_back_bonus.c ft_lstnew_bonus.c  ft_lstclear_bonus.c  ft_lstadd_front_bonus.c \
         ft_lstdelone_bonus.c  ft_lstsize_bonus.c  ft_lstlast_bonus.c   ft_lstiter_bonus.c  \
         ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)
OBJB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJB)
	$(AR) $(NAME) $?
	touch bonus

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re
