
#SETUP
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	push_swap.h

SRCS    	=	push_swap.c
OBJ_SRCS    =	$(SRCS:.c=.o)

#FUNCTIONS

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_memcpy.c ft_strlen.c ft_atoi.c ft_checks.c ft_sort.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)


#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_SRCS)
				@$(CC) $(FLAGS) $(OBJ_F) $(OBJ_SRCS) -o $(NAME)
				@echo "$(NAME) created!"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_SRCS)
				@$(RM) $(OBJ_F)
				@echo "object files deleted!"

fclean:			clean
				@$(RM) $(NAME)
				@echo "all deleted!"

re:				fclean all

.PHONY:		all clean fclean bonus re
