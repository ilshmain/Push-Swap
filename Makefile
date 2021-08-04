NAME	= push_swap
CC		:= gcc
SRC_DIR	= src/
OBJ_DIR	= obj/
HEADER	= -I includes
SRCS	:= $(wildcard $(SRC_DIR)*)
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra
OBJS	:= $(addprefix $(OBJ_DIR),$(addsuffix .o ,$(basename $(notdir $(SRCS)))))
all:	obj	${NAME}

obj:	$(SRCS)
					@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
					$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
$(NAME): $(OBJS)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(HEADER)
clean:
					${RM} ${OBJ_DIR}
fclean:				clean
					${RM} ${NAME}
re:					fclean all
.PHONY:				all clean fclean re