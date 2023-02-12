NAME		= push_swap
SRC_DIR		= srcs
OBJ_DIR		= objs
SRC_NAME	= push_swap.c\
			  swap.c\
			  push.c\
			  rotate.c\
			  push_utils.c\
			  push_utils2.c\
			  list_search.c\
			  errors.c\
			  errors2.c\
			  pars_utils.c




OBJ_NAME		=	$(SRC_NAME:%.c=%.o)

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

####Compil####

CC 		= gcc -O3 -g
CFLAGS 	= -Wall -Wextra -Werror

### DEBUG ####
D = 0
ifeq ($(D), 1)
	CC += -fsanitize=address -g3
	MODE = printf %b "\033[0;31m MODE DEBUG SANITIZE \033[0m"
endif
ifneq ($(D), 1)
	MODE = printf %b "\033[0;31m MODE RELEASE \033[0m"
endif

#####LIBS#####

LIBS	= LIBFT/libft.a
LIBH	= LIBFT/libft.h push_swap.h
CH_FLAG	= -I. -ILIBFT

## Rules ##

all:			$(NAME)

LIBFT/libft.a:
	@make --no-print-directory all -C LIBFT

$(NAME):	$(LIBS) $(OBJ)
	@$(CC) $^ -o $(NAME) $(CFLAGS) $(CH_FLAG) -L./LIBFT -lft
	@printf %b  "\033[1;35m-[$(NAME)]__Edit/Create .o in \033[0m  \033[0;32m[OK]\033[0m\n"
	@printf %b  "\r"
	@$(MODE)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(LIBH) LIBFT
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CH_FLAG) -o $@ -c $<
	@printf %b "-\033[1;35m[$(NAME)]\033[0m__Compiling \033[1;92m$<\033[0m in \033[1;92m$@\033[0m..."
	@printf "\r"

clean:
	@rm -rf $(OBJ)
	@make --no-print-directory clean -C LIBFT
	@printf %b  "-\033[1;33m[$(NAME)]__Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m\n"


fclean: clean
	@rm -rf $(NAME)
	@make --no-print-directory fclean -C LIBFT
	@printf %b  "-\033[1;33m[$(NAME)]__Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
