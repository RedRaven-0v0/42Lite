# -------------------------------------------------- #
#                   VARIABLES                        #
# -------------------------------------------------- #

NAME = game.bin

CXX = c++
CXXFLAGS = -std=c++17 -g3 -I includes -I hero -I enemies -I upgrades

SRC_DIR = .
OBJ_DIR = obj

HEADERS = \
	includes/game.hpp \
	includes/includes.hpp \
	includes/structs.hpp \
	includes/character.hpp \
	hero/hero.hpp \
	enemies/enemies.hpp \
	upgrades/upgrades.hpp

SRCS = \
	srcs/main.cpp \
	srcs/utils/create_hero.cpp \
	srcs/utils/load_enemies.cpp \
	srcs/utils/load_upgrades.cpp \
	srcs/utils/to_continue.cpp \
	srcs/utils/e_d_input.cpp \
	srcs/utils/get_random_enemy.cpp \
	srcs/utils/display_hero_enemy.cpp \
	srcs/utils/slow_print.cpp \
	srcs/scripts/bienvenue.cpp \
	srcs/scripts/mid_fight_script.cpp \
	srcs/scripts/final_fight_script.cpp \
	srcs/scripts/victory_script.cpp \
	srcs/scripts/first_rest.cpp \
	srcs/scripts/first_shop.cpp \
	srcs/scripts/script_dead.cpp \
	srcs/menus/new_adventure.cpp \
	srcs/menus/final_fight.cpp \
	srcs/menus/new_fight.cpp \
	srcs/menus/rest.cpp \
	srcs/menus/shop.cpp \
	srcs/battle/auto_battle.cpp \
	includes/character.cpp \
	hero/hero.cpp \
	enemies/enemies.cpp \
	upgrades/upgrades.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

MKDIR = mkdir -p
RM = rm -rf

# -------------------------------------------------- #
#                   RULES                            #
# -------------------------------------------------- #

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@echo "Compiling $< ..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "[DONE] Compilation successful."

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

clean:
	@echo "Cleaning objects..."
	@$(RM) $(OBJ_DIR)
	@echo "[DONE] Object files removed."

fclean: clean
	@echo "Removing binary..."
	@$(RM) $(NAME)
	@echo "[DONE] Full clean complete."

re: fclean all
	@echo "[DONE] Rebuild complete."

run: all
	@echo "Running $(NAME)..."
	@./$(NAME)

.PHONY: all clean fclean re run
