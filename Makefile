# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 10:25:22 by cyun              #+#    #+#              #
#    Updated: 2022/12/27 15:41:34 by cyun             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME= server
NAMEC= client

all: server client

server:
	gcc server.c utils.c -o $(NAME)

client:
	gcc client.c utils.c -o $(NAMEC)

bonus: server_bonus client_bonus

server_bonus:
	gcc server_bonus.c utils.c -o $(NAME)

client_bonus:
	gcc client_bonus.c utils.c -o $(NAMEC)

clean:
	rm -rf $(NAME) $(NAMEC)

fclean: clean

re: fclean all