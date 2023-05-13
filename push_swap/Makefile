NAME 			= push_swap

LIBFT			= libft.a

LIBFT_PATH 		= ./libft/
SRC_PATH 		= ./src/
OBJ_PATH		= ./obj/
INCLUDE 		= ./include/

#compilation
CC 				= cc
CF 				= -Wall -Wextra -Werror
CFI 			= -I $(INCLUDE)

SRC = sort.c \
			list_op.c \
			swap.c \
			ft_build_stack.c \
			bubble_sort.c \
			main.c \
			five_sort.c \
			sort_array.c \
			check_args.c

OBJ				= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

#common commands
RM 				= rm -rf

#rules
$(OBJ_PATH)%.o: 	$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(CF) $(CFI) -c $< -o $@
				

$(NAME):		$(OBJ)
				make -C $(LIBFT_PATH) $(LIBFT)
				$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft

all:			$(NAME)


re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ) $(OBJ_BONUS) $(OBJDIR)

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS)

.PHONY:			all clean fclean re bonus rebonus

