# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 12:37:08 by cpeset-c          #+#    #+#              #
#    Updated: 2024/03/01 16:32:24 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	DEFINE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Here define the lenguage for the Makefile.
LANG	:= C++

SYSTEM	:= $(shell uname -s)

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME    	:= atLeastThisBeatsCoffeeMaking

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

CFLAGS		:= -Wall -Wextra -Werror -W -pedantic
ifeq ($(LANG), C++)
	CFLAGS	+= -std=c++98
endif

XFLAGS		= #-fsanitize=address -g
DFLAGS		= -MT $@ -MMD -MP

AR		= ar -rcs
RM		= rm -f
MK		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

OBJ_DIR	:= .objs/
DEP_DIR	:= .deps/

# Bureaucrat Class Folder
BRC_DIR	:= ./BureaucratClass/

# Abstract Form Class Folder
FRM_DIR	:= ./AbstractFormClass/

# PresidentPardonForm Class Folder
PPF_DIR	:= ./PresidentialPardonFormClass/

# RobotomyRequestForm Class Folder
RRF_DIR	:= ./RobotomyRequestFormClass/

# ShrubberyCreationForm Class Folder
SCF_DIR	:= ./ShrubberyCreationFormClass/

# Intern Class Folder
INT_DIR	:= ./InternClass/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

ifeq ($(LANG), C)
	EXT	:= .c
endif
ifeq ($(LANG), C++)
	EXT	:= .cpp
endif

INCLUDE	:= -I./$(BRC_DIR) -I./$(FRM_DIR) -I./$(PPF_DIR) -I./$(RRF_DIR) -I./$(SCF_DIR) -I./$(INT_DIR)

# -----------------------------  SOURCE FILES  -------------------------------- #

# Bureaucrat Class Files
BRC_SRC	:= Bureaucrat.cpp

# AbstractForm Class Files
FRM_SRC	:= AForm.cpp

# PresidentPardonForm Class Files
PPF_SRC	:= PresidentialPardonForm.cpp

# RobotomyRequestForm Class Files
RRF_SRC	:= RobotomyRequestForm.cpp

# ShrubberyCreationForm Class Files
SCF_SRC	:= ShrubberyCreationForm.cpp

# Intern Class Files
INT_SRC	:= Intern.cpp

# -----------------------------  MAIN FILES  ---------------------------------- #
SRCS	+= ./main.cpp
SRCS	+= $(addprefix $(BRC_DIR), $(BRC_SRC))
SRCS	+= $(addprefix $(FRM_DIR), $(FRM_SRC))
SRCS	+= $(addprefix $(PPF_DIR), $(PPF_SRC))
SRCS	+= $(addprefix $(RRF_DIR), $(RRF_SRC))
SRCS	+= $(addprefix $(SCF_DIR), $(SCF_SRC))
SRCS	+= $(addprefix $(INT_DIR), $(INT_SRC))

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
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) *_shrubbery
	@echo "$(BLUE)	Cub3D object and dependencies files cleaned.$(DEF_COLOR)"

fclean: 
	@$(RM) -r $(OBJ_DIR) $(DEP_DIR) $(NAME) *_shrubbery
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