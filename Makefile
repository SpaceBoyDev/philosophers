# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dario <dario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 18:40:53 by dario             #+#    #+#              #
#    Updated: 2025/05/04 00:15:43 by dario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra #-Werror -g3
RM			=	rm -f

DIR			=	srcs/
HDERS		=	$(DIR)philosophers.h
# SRCS		=	$(DIR)main.c $(DIR)philosophers.c $(DIR)utils.c
SRC			=	main.c philosophers.c utils.c handle_errors.c initialization.c \
				debug.c
SRCS		=	$(addprefix $(DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

RESET		=	\033[0m
GREEN		=	\033[1;32m
RED			=	\e[1;31m
YELLOW		=	\e[1;33m
BLUE		=	\033[0;34m
CIAN		=	\e[7;36m

all: $(NAME)

run: all
	./philo 10 10 10 10 10

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CIAN)Philosophers compiled!$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "$(CIAN)Cleaning up objects...$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(CIAN)Cleaning up program...$(RESET)"

re: fclean all

norme:
	@echo "$(CIAN)SOURCES$(RESET)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(RESET)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(RESET)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS$(RESET)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(RESET)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(RESET)"; \
		fi \
	done

.PHONY: all clean fclean re