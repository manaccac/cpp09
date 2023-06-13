# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER        = RPN.hpp
SRC_PATH      = sources
SRCS_NAME     = RPN.cpp main.cpp
OBJS          = ${SRCS_NAME:.cpp=.o}
NAME          = RPN
RM            = rm -f
FLAGS         = -Wall -Wextra -Werror
SRCS          = $(addprefix $(SRC_PATH)/,$(SRCS_NAME))

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(NAME)

%.o: %.cpp $(HEADER)
	@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
	@g++ $(FLAGS) -I . -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling RPN\033[0m"
	@g++ -o $(NAME) $(OBJS)

clean:
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing object files\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
