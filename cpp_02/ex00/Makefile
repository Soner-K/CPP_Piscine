NAME := ex00
SRC_FILES := Fixed.cpp main.cpp
OBJ_FILES := $(patsubst %.cpp, obj/%.o, $(SRC_FILES))
CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(GREY)Compiling project...$(NEUTRAL)"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@printf "$(GREEN)$(NAME) compiled !$(NEUTRAL)\n"

obj/%.o: %.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "Object file$(LYELLOW) %s$(NEUTRAL) created !\n" $@

clean:
	@echo "$(LRED)Removing object files...$(NEUTRAL)"
	rm -rf obj
	@echo "$(LRED)Done !$(NEUTRAL)"

fclean: clean
	@echo "$(RED)Removing executable...$(NEUTRAL)"
	@echo "$(RED)Done !$(NEUTRAL)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




NEUTRAL =\033[0m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
RED =\033[1;31m
LYELLOW =\033[0;33m
LRED =\033[0;31m
GREY =\033[1;37m