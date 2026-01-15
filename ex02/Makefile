SRCS =  main.cpp
HEADER =  ./hpp/Array.hpp ./cpp/Array.tpp

OBJS = $(SRCS:.cpp=.o)
NAME = defoult_
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(HEADER)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all