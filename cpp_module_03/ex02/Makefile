# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:59:45 by cpeset-c          #+#    #+#              #
#    Updated: 2024/02/17 13:00:04 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	DEFINE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

# Here define the lenguage for the Makefile.
LANG	:= C++

SYSTEM	:= $(shell uname -s)

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME    	:= repetitiveWork

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


CTC_DIR := ClapTrapClass/
CTC_SRC_DIR	:= $(CTC_DIR)src/
CTC_INC_DIR	:= $(CTC_DIR)inc/

STC_DIR := ScavTrapClass/
STC_SRC_DIR	:= $(STC_DIR)src/
STC_INC_DIR	:= $(STC_DIR)inc/

FTC_DIR := FragTrapClass/
FTC_SRC_DIR	:= $(FTC_DIR)src/
FTC_INC_DIR	:= $(FTC_DIR)inc/

OBJ_DIR	:= .objs/
DEP_DIR	:= .deps/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

ifeq ($(LANG), C)
	EXT	:= .c
endif
ifeq ($(LANG), C++)
	EXT	:= .cpp
endif

INCLUDE	:= -I./$(CTC_INC_DIR) -I./$(STC_INC_DIR) -I./$(FTC_INC_DIR)

CTC_SRC_FLS = ClapTrap.cpp

STC_SRC_FLS = ScavTrap.cpp

FTC_SRC_FLS = FragTrap.cpp

SRCS	= main.cpp
SRCS	+= $(addprefix $(CTC_SRC_DIR), $(CTC_SRC_FLS))
SRCS	+= $(addprefix $(STC_SRC_DIR), $(STC_SRC_FLS))
SRCS	+= $(addprefix $(FTC_SRC_DIR), $(FTC_SRC_FLS))


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