# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lps <lps@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 17:08:14 by lps               #+#    #+#              #
#    Updated: 2024/09/23 17:08:16 by lps              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ircserv

SRCS	= main.cpp Server.cpp Client.cpp Channel.cpp pass.cpp parsing.cpp\
		nick.cpp user.cpp quit.cpp Privmsg.cpp utils.cpp Mode.cpp pong.cpp \
		join.cpp kick.cpp part.cpp invite.cpp topic.cpp list.cpp notice.cpp

OBJS	= ${SRCS:.cpp=.o}

CXX		= c++

CXXFLAGS	=  -Werror -Wextra -Wall -std=c++98


OBJ = ${SRC:%.cpp=%.o}

all:	${NAME}

${NAME}:	${OBJS}
		$(CXX) ${CXXFLAGS} ${OBJS} -o $(NAME)

clean:		
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${NAME}

re:			fclean all

.PHONY: all clean fclean re
