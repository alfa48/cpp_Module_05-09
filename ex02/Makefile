# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manandre <manandre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 14:29:21 by manandre          #+#    #+#              #
#    Updated: 2025/10/07 22:35:03 by manandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 	Bureaucrat.cpp\
		form/cpp/AForm.cpp\
		form/cpp/ShrubberyCreationForm.cpp\
		form/cpp/RobotomyRequestForm.cpp\
		form/cpp/PresidentialPardonForm.cpp\
		main.cpp\

HEADER = Bureaucrat.hpp\
		 form/hpp/AForm.hpp\
		 form/hpp/ShrubberyCreationForm.hpp\
 		 form/hpp/RobotomyRequestForm.hpp\
		 form/hpp/PresidentialPardonForm.hpp\


OBJS = $(SRCS:.cpp=.o)
NAME = bureaucrat_form
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