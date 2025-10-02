/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 14:29:21 by manandre          #+#    #+#             */
/*   Updated: 2025-10-02 14:29:21 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


SRCS = Bureaucrat.cpp main.cpp Form.cpp
HEADER = Bureaucrat.hpp Form.hpp

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