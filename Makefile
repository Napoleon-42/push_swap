
NAME		= push_swap

HEDS_PATH	= headers/

SRCS_PATH	= srcs/

LIBFT_PATH	= ${SRCS_PATH}libft

CHECK_PATH	= checker_/

OBJS_PATH	= obj/

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I ${HEDS_PATH}

FLAGS		= -L ${LIBFT_PATH} -lft

CFILES		=\
			push_swap.c\
			binary_sort.c\
			input_check.c\
			operations_1.c\
			operations_2.c\
			radix_sort.c\
			utils.c\
			utils_2.c\
			under_5.c\
			under_5_utils.c\

SRCS		= ${addprefix ${SRCS_PATH}, ${CFILES}}

OBJS		= ${SRCS:.c=.o}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT_PATH}
			${CC} -o ${NAME} ${OBJS} ${FLAGS}

sssan:		${OBJS}
			make -C ${LIBFT_PATH}
			${CC} -o ${NAME} ${OBJS} ${FLAGS} -g3 -fsanitize=address

my:			all clean
						
clean:		
				${RM} ${OBJS}
				make clean -C ${LIBFT_PATH}
				
fclean:		 clean
				make fclean -C ${LIBFT_PATH}
				${RM} ${NAME}

re:			fclean all

RM			= rm -rf
