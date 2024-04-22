NAME	=	push_swap
CC		=	gcc
INCLUDE =	include
CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCLUDE)

SRC 	=	src/push_swap.c\
			src/parsing/ft_verify.c\
			src/ps_functions/pa.c\
			src/ps_functions/pb.c\
			src/ps_functions/ra.c\
			src/ps_functions/rb.c\
			src/ps_functions/rr.c\
			src/ps_functions/rra.c\
			src/ps_functions/rrb.c\
			src/ps_functions/rrr.c\
			src/ps_functions/sa.c\
			src/ps_functions/sb.c\
			src/ps_functions/ss.c\
			src/sort_functions/sort_stack.c\
			src/sort_functions/sort_three.c\
			src/sort_functions/sort_big.c\
			src/utils/clear_stack.c\
			src/utils/count_stack.c\
			src/utils/create_node.c\
			src/utils/create_stack.c\
			src/utils/find_biggest.c\
			src/utils/is_sorted.c

LIBFT	=	@make -C libft
LIBFTA	=	libft/libft.a

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC) $(OBJ)
	$(LIBFT)
	$(LIBFT) bonus
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTA) -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re