NAME = 	libftprintf.a

SRCS =	push_swap.c			work_argc.c		sortirovka.c		ps_dop_func_1.c		ft_split.c		ft_strlcpy.c		true_false.c\
		ft_lstadd_back.c
		
HEADER = libftprintf.h

OBJS = $(patsubst %.c, %.o, $(SRCS))

FLAGS  = -Wall -Wextra -Werror

ARCS = ar rcs

RM	= rm -f

all : $(NAME)

$(NAME)	: $(OBJS)
	$(ARCS)	$(NAME)	$?

bonus :
	@make OBJS="$(OBJS_1)" all

%.o : %.c $(HEADER)
	gcc -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_1)

fclean : clean
	$(RM) $(NAME)

re : fclean all

test1 : 
	gcc $(SRCS) && ./a.out 8 5 10 12 1

test2 : 
	gcc $(SRCS) && ./a.out -8 5 +10 12 1 45 -6
	
.PHONY : all bonus clean fclean re