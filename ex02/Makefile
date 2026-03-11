SRCS =  main.cpp PmergeMe.cpp
HEADER =  PmergeMe.hpp

OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all