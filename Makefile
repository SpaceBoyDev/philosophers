# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/05/03 21:40:51 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra #-Werror -g3
RM			=	rm -f

DIR			=	srcs/
HDERS		=	$(DIR)philosophers.h
# SRCS		=	$(DIR)main.c $(DIR)philosophers.c $(DIR)utils.c
SRC			=	main.c philosophers.c utils.c handle_errors.c initialization.c
SRCS		=	$(addprefix $(DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

COLOREND	=	\033[0m
GREEN		=	\033[1;32m
RED			=	\e[1;31m
YELLOW		=	\e[1;33m
BLUE		=	\033[0;34m
CIAN		=	\e[7;36m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norme:
	@echo "$(CIAN)SOURCES$(COLOREND)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS$(COLOREND)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(COLOREND)"; \
		fi \
	done

.PHONY: all clean fclean re