SRC = init.c time.c main.c check.c philo_utils.c utils.c

NAME = philo
FLAGS = -Wextra -Werror -Wall -pthread
OBJS = ${SRC:.c=.o}

all : ${NAME}

${OBJS} : %.o:%.c
		cc ${FLAGS} -c $< -o $@

${NAME} : ${OBJS}
		cc ${FLAGS} ${OBJS} -o ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re :	fclean all

.PHONY : all clean  fclean 