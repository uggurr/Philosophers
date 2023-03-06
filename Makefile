NAME:= philo
CC:= gcc
FLAGS:= -Wall -Wextra -Werror

SRCS   :=      dead.c \
           get_args.c \
           philo.c \
           threads.c \
           time.c \
           utils.c \
           write.c \

OBJS:= $(SRCS:.c=.o)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}
RM:= rm -f

$(NAME): ${OBJS}
	@echo "[COMPILING...]"
	@$(CC) $(FLAGS) $(OBJS) -o ${NAME}
	@echo "COMPILING FINISHED"

all: ${NAME}

clean:
	@echo "[DELETING...]"
	@${RM} ${OBJS}
	@echo "DELETED"
fclean: clean
	@${RM} ${NAME}
re: fclean all
