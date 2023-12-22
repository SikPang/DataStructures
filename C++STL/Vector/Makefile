NAME	= a.out

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++11 -fsanitize=address -g

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o		: %.cpp
	$(CC) $(CFLAGS) -c $<

clean	:
	rm -f $(OBJS)

fclean	:
	make clean
	rm -f $(NAME)

re		:
	make fclean
	make all

.PHONY	: all clean fclean re