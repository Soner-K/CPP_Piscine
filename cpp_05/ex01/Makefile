NAME := Form
SRC_FILES := main.cpp Bureaucrat.cpp Form.cpp
OBJ_DIR := obj
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEPS := $(OBJ_FILES:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)
CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(GREY)Compiling project...$(NEUTRAL)"
	$(CXX) $(CXXFLAGS) -o $@ $^
	@toilet -f mono12 --metal $(NAME)

obj/%.o: %.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	@printf "Object file$(YELLOW) %s$(NEUTRAL) created !\n" $@
-include $(DEPS)

clean:
	@echo "$(LRED)Removing object files...$(NEUTRAL)"
	rm -rf obj
	@echo "$(LRED)Done !$(NEUTRAL)"

fclean: clean
	@echo "$(RED)Removing executable...$(NEUTRAL)"
	rm -f $(NAME)
	@echo "$(RED)Done !$(NEUTRAL)"

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