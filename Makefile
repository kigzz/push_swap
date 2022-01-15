
#SETUP
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	push_swap.h

SRCS    	=	push_swap.c error.c ft_checks.c push_swap_utils.c
SRCS_DIR	=	sources/
SRCS_PATH	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS    =	$(SRCS_PATH:.c=.o)

#FUNCTIONS

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_memcpy.c ft_strlen.c ft_atoi.c ft_isdigit.c \
                ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)


#COMMANDS
%.o : %.c
				@${CC} ${FLAGS} -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_F) $(OBJ_SRCS)
				@$(CC) $(FLAGS) $(OBJ_F) $(OBJ_SRCS) -o $(NAME)
				@echo "$(NAME) created!"


clean:
				@$(RM) $(OBJ_SRCS)
				@$(RM) $(OBJ_F)
				@echo "object files deleted!"

fclean:			clean
				@$(RM) $(NAME)
				@echo "all deleted!"

re:				fclean all

.PHONY:		all clean fclean bonus re
