MAKEFLAGS = --silent
#BLACK			= 	\033[1;30m#			#RED			=	\033[1;31m#
GREEN			=	\033[3;32m#			#YELLOW      	=	\033[1;33m#
#BLUE			=	\033[1;34m#			#MAGENTA		=	\033[1;35m#
#CYAN			=	\033[1;36m#			#WHITE			=	\033[4;37m#
DEFAULT			=	\033[0m#
#ONELINEUP		=	"\033[1A"			#ERASELINE		=	"\033[K"
#NORMAL			[0;		#BOLD			[1;		#DIM			[2;
#ITALIC			[3;		#UNDERLINED		[4;		#BLINK			[5;
#REVERSEBG		[7;		#HIDDEN			[8;		#STRIKETHROUGH	[9;
# To format, use the following syntax: \033[STYLE;TEXT;BACKGROUNDm
# For example, to print a bold red text on a blue background, use: \033[1;31;44m
# To combine styles, use a semicolon: \033[1;4;31m (bold + underlined, red text)
# Rainbow: \033[1;31mR\033[1;33mY\033[1;32mG\033[1;36mC\033[1;34mB\033[1;35mV
NAME	= agu
SOURCESPATH	= ./
SOURCESLIST	= Casio.cpp Contact.cpp Display.cpp Organiser.cpp PhoneBook.cpp
SOURCES = $(addprefix $(SOURCESPATH), $(SOURCESLIST))

COMPILE	= c++
FLAGS	= -Wall -Wextra -Werror -O3 -std=c++98
# Replaced -g with -O3 to optimise the code (removing debug symbols).
# -O3 is faster than -g and -O2, but it takes longer to compile.
REMOVE	= rm -f
VALGRIND	= valgrind -s --leak-check=full --show-leak-kinds=all
# -s to suppress the summary, -v to show the full report.
# --track-origins=yes to show where the memory was allocated.

.c.o:
	$(COMPILE) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):
	$(COMPILE) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	@$(REMOVE) $(NAME)
	echo "$(GREEN)Limpíssimo!$(DEFAULT)"

clean: fclean

re:		fclean all

run:	$(NAME)
	./$(NAME)

vrun:	$(NAME)
	$(VALGRIND) ./$(NAME)

rerun:	re run

# Ignores files that could eventually be named after any of these rules.
.PHONY:		all clean fclean re
