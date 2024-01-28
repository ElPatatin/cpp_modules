# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 12:37:08 by cpeset-c          #+#    #+#              #
#    Updated: 2024/01/28 20:54:25 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	DEFINE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Here define the lenguage for the Makefile.
LANG	:= C++

SYSTEM	:= $(shell uname -s)

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME    	:= iDontWantToSetTheWorldOnFire

MKFL		:= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_CLR		:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Define Compiler for MacOS or Linux system.

ifeq ($(LANG), C)
	ifeq ($(SYSTEM), Darwin)
		CC	:= clang
	endif
	ifeq ($(SYSTEM), Linux)
		CC	:= gcc
	endif
else ifeq ($(LANG), C++)
	ifeq ($(SYSTEM), Darwin)
		CC	:= clang++
	endif
	ifeq ($(SYSTEM), Linux)
		CC	:= g++
	endif
endif

# Define compiler flags.

CFLAGS		:= -Wall -Wextra -Werror -W
ifeq ($(LANG), C++)
	CFLAGS	+= -std=c++98
endif

XFLAGS		= #-fsanitize=address -g
LFLAGS		= #-fsanitize=leak
DFLAGS		= -MT $@ -MMD -MP

AR		= ar -rcs
RM		= rm -f
MK		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Clap Trap Class Folder
ANC_DIR := AnimalClass/
ANC_SRC_DIR	:= $(ANC_DIR)src/
ANC_INC_DIR	:= $(ANC_DIR)inc/

# Dog Class Folder
DOC_DIR := DogClass/
DOC_SRC_DIR	:= $(DOC_DIR)src/
DOC_INC_DIR	:= $(DOC_DIR)inc/

# Cat Class Folder
CAC_DIR := CatClass/
CAC_SRC_DIR	:= $(CAC_DIR)src/
CAC_INC_DIR	:= $(CAC_DIR)inc/

# Wrong Animal Class Folder
WAC_DIR	:= WrongAnimalClass/
WAC_SRC_DIR	:= $(WAC_DIR)src/
WAC_INC_DIR	:= $(WAC_DIR)inc/

# Wrong Animal Class Folder
WCC_DIR	:= WrongAnimalClass/
WCC_SRC_DIR	:= $(WCC_DIR)src/
WCC_INC_DIR	:= $(WCC_DIR)inc/

# Brain Class Folder
BRC_DIR	:= BrainClass/
BRC_SRC_DIR	:= $(BRC_DIR)src/
BRC_INC_DIR	:= $(BRC_DIR)inc/

# Object and Dependencies Folder
OBJ_DIR	:= .objs/
DEP_DIR	:= .deps/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

ifeq ($(LANG), C)
	EXT	:= .c
endif
ifeq ($(LANG), C++)
	EXT	:= .cpp
endif

INCLUDE	:= -I./$(ANC_INC_DIR) -I./$(DOC_INC_DIR) -I./$(CAC_INC_DIR) -I./$(WAC_INC_DIR) -I./$(WCC_INC_DIR) -I./$(BRC_INC_DIR)

# Animal Class Files
ANC_SRC_FLS = ClapTrap.cpp

# Dog Class Files
DOC_SRC_FLS = ScavTrap.cpp

# Cat Class Files
CAC_SRC_FLS = FragTrap.cpp

# Wrong Animal Class Files
WAC_SRC_FLS = DiamondTrap.cpp

# Wrong Cat Class Files
WCC_SRC_FLS = main.cpp

# Brain Class Files
BRC_SRC_FLS = Brain.cpp

# Main Files
SRCS	= ./main.cpp
SRCS	+= $(addprefix $(ANC_SRC_DIR), $(ANC_SRC_FLS))
SRCS	+= $(addprefix $(DOC_SRC_DIR), $(DOC_SRC_FLS))
SRCS	+= $(addprefix $(CAC_SRC_DIR), $(CAC_SRC_FLS))
SRCS	+= $(addprefix $(WAC_SRC_DIR), $(WAC_SRC_FLS))
SRCS	+= $(addprefix $(WCC_SRC_DIR), $(WCC_SRC_FLS))
SRCS	+= $(addprefix $(BRC_SRC_DIR), $(BRC_SRC_FLS))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:$(EXT)=.o))
DEPS	= $(addprefix $(DEP_DIR), $(addsuffix .d, $(basename $(SRCS))))


# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31m$(NAME) $(WHITE)has been compiled!$(DEF_COLOR)\n"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31m$(NAME)$(DEF_COLOR)\n"

-include $(DEPS)

clean:
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR)
	@echo "$(BLUE)	Cub3D object and dependencies files cleaned.$(DEF_COLOR)"

fclean: 
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE)
	@echo "$(GREEN)	Cleaned and rebuilt everything for $(NAME) project.$(DEF_COLOR)"

$(OBJ_DIR)%.o: %$(EXT) $(MKFL)
	@$(MK) $(dir $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_CLR)                   \r"
	@$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR), $(DEP_DIR), $@))

.PHONY: all clean fclean re