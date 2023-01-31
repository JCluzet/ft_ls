NAME = libft.a

SRC =  ft_atoi.c\
                ft_split.c\
                ft_bzero.c\
                ft_strchr.c\
                ft_calloc.c\
                ft_strdup.c\
                ft_isdigit.c\
                ft_strjoin.c\
                ft_isalpha.c\
                ft_memccpy.c\
                ft_strlcat.c\
                ft_isascii.c\
                ft_memchr.c\
                ft_strlcpy.c \
                ft_isalnum.c\
                ft_memcmp.c\
				ft_printf.c\
                ft_strlen.c\
                ft_isprint.c\
                ft_memcpy.c\
                ft_strmapi.c\
                ft_itoa.c\
                ft_memmove.c\
                ft_strncmp.c\
                ft_memset.c\
                ft_strnstr.c\
                ft_putchar_fd.c\
                ft_strtrim.c\
                ft_putendl_fd.c\
                ft_substr.c\
                ft_putnbr_fd.c\
                ft_tolower.c\
                ft_putstr_fd.c\
                ft_toupper.c\
                ft_strrchr.c\
				printf_src/type_c.c\
				printf_src/type_d.c\
				printf_src/type_p.c\
				printf_src/type_pourc.c\
				printf_src/type_s.c\
				printf_src/type_u.c\
				printf_src/type_x.c\
				printf_src/type_xmaj.c\
				printf_src/utils.c\
				printf_src/utils2.c\

SRC_BONUS = ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_O = $(SRC:.c=.o)

SRC_BONUS_O = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SRC_O)
		$(CC) $(FLAGS) -c $(SRC)
		ar rcs $(NAME) $(SRC_O)

bonus : $(SRC_BONUS_O)
		$(CC) $(FLAGS) -c $(SRC) $(SRC_BONUS)
		ar rcs $(NAME) $(SRC$_O) $(SRC_BONUS_O)

clean:
	rm -rf  $(SRC_O) $(SRC_BONUS_O)
    

fclean: clean
		rm -rf $(NAME)

re: 	fclean all clean

cleanall: 
	rm *.o *.a a.out
