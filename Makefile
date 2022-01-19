
#SETUP
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	push_swap.h

SRCS    	=	push_swap.c ft_checks.c ft_creating.c ft_free.c ops_p.c ops_s.c ops_r.c ops_rr.c
SRCS_DIR	=	sources/
SRCS_PATH	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS    =	$(SRCS_PATH:.c=.o)

#FUNCTIONS

FUNC_SRCS	=	ft_strdup.c ft_split.c ft_memcpy.c ft_strlen.c ft_atoi.c ft_isdigit.c \
                ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c ft_dlstadd_back.c ft_dlstadd_front.c \
                ft_dlstfirst.c ft_dlstlast.c ft_dlstnew.c ft_dlstsize.c
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
