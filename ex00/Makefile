# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manandre <manandre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 20:35:27 by manandre          #+#    #+#              #
#    Updated: 2025/09/30 08:39:49 by manandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = Bureaucrat.cpp main.cpp
HEADER = Bureaucrat.hpp

OBJS = $(SRCS:.cpp=.o)
NAME = bureaucrat
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