SRCS =  cpp/Base.cpp cpp/A.cpp cpp/B.cpp  cpp/C.cpp main.cpp
HEADER =  hpp/Base.hpp hpp/A.hpp hpp/B.hpp  hpp/C.hpp

OBJS = $(SRCS:.cpp=.o)
NAME = realType
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