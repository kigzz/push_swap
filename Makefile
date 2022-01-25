
#SETUP

NAME			=	push_swap
CHECKER_NAME	=	checker
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

#FILES AND PATH

SRCS    		=	push_swap.c ft_checks.c ft_creating.c ft_free.c ops_p.c ops_s.c ops_r.c ops_rr.c sort_small.c \
					handle_sort.c sort_small_utils.c sort_big.c sort_big_utils.c ft_check2.c
SRCS_DIR		=	sources/
SRCS_PATH		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJ_SRCS    	=	$(SRCS_PATH:%.c=%.o)

CHECKER_SRCS	=	checker.c ops_p.c ops_s.c ops_r.c ops_rr.c ft_checks.c ft_creating.c ft_free.c ft_check2.c
CHECKER_DIR		=	sources/
CHECKER_PATH	=	$(addprefix $(CHECKER_DIR), $(CHECKER_SRCS))
CHECKER_OBJ		=	$(CHECKER_PATH:%.c=%.o)

#FUNCTIONS

FUNC_SRCS		=	ft_strdup.c ft_split.c ft_memcpy.c ft_strlen.c ft_atoi.c ft_isdigit.c \
                	ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c ft_dlstadd_back.c ft_dlstadd_front.c \
                	ft_dlstfirst.c ft_dlstlast.c ft_dlstnew.c ft_dlstsize.c ft_strcat.c ft_strcpy.c \
                	get_next_line.c ft_strncmp.c ft_strchr.c ft_substr.c ft_strlcpy.c
FUNC_DIR		=	functions/
FUNC 			=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F			=	$(FUNC:%.c=%.o)

#COMMANDS

%.o : %.c
					@$(CC) $(FLAGS) -c $< -o $@

all:				$(NAME) $(CHECKER_NAME)

$(NAME):			$(OBJ_F) $(OBJ_SRCS)
					@$(CC) $(FLAGS) $(OBJ_F) $(OBJ_SRCS) -o $(NAME)
					@echo "$(NAME) created!"

$(CHECKER_NAME):	$(OBJ_F) $(CHECKER_OBJ)
					@$(CC) $(FLAGS) $(OBJ_F) $(CHECKER_OBJ) -o $(CHECKER_NAME)
					@echo "$(CHECKER_NAME) created"
clean:
					@$(RM) $(OBJ_SRCS)
					@$(RM) $(OBJ_F)
					@$(RM) $(CHECKER_OBJ)
					@echo "object files deleted!"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(CHECKER_NAME)
				@echo "all deleted!"

re:				fclean all

.PHONY:		all clean fclean bonus re
