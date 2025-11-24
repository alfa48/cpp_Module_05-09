SRCS = cpp/Serializer.cpp main.cpp
HEADER = hpp/Data.hpp hpp/Serializer.hpp

OBJS = $(SRCS:.cpp=.o)
NAME = serialize
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