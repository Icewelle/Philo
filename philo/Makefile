# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cluby <cluby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 12:48:03 by cluby             #+#    #+#              #
#    Updated: 2024/11/19 13:30:59 by cluby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
C = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -g3 -pthread
SRC =	main.c\
		srcs/create_thread.c\
		srcs/errors.c\
		srcs/init_philo.c\
		srcs/routine.c\
		srcs/utils.c\
		srcs/parsing.c\
		srcs/utils2.c
OBJ = $(SRC:.c=.o)
NAME = philo

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
COMP_END	=	echo "\n🏗️ $(BOLD_YELLOW)Make: $(NO_COLOR)Compilation done\n"
CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

all : $(NAME)

$(NAME) : $(OBJ)
	@$(COMP_START)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
	@$(COMP_END)

clean :
	rm -f $(OBJ)
	@$(CLEANED)

fclean : clean
	rm -f $(NAME)
	@$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re