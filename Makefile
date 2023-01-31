#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := ls
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "Compilation of LIBFT..."
			@make -C libft
			@echo "$(GREEN)LIBFT compiled ✔️"
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@gcc -o ls ${SRCS} libft/libft.a
			@echo "$(GREEN)$(NAME) compiled ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re


