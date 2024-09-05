# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: val <val@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 20:05:42 by ghusk             #+#    #+#              #
#    Updated: 2020/07/08 17:27:30 by val              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname -s)

PS := push_swap
CH := checker
CC := gcc -g -Wall -Wextra -Werror
LIBD := libft/
LIB := $(LIBD)libft.a
PSC :=	blocks\
		error\
		finder\
		ft_checker2\
		ft_listi\
		ft_push_swap\
		funcsh\
		smart_sort\

CHC :=	finder\
		ft_checker\
		ft_checker2\
		ft_listi\
		funcsh\
		get_command\
		grafic_draw_head\
		grafic_draw_text\
		grafic_field_counter\
		grafic_find_list\
		grafic_init\
		grafic_stack\
		grafic_stack_b\
		grafic_storage\
		grafics\
		visual\
		error

SRC := src/

SRCO := srco/

INC :=	-I $(LIBD)includes/\
		-I includes/

ifeq ($(OS), Linux)

	SDL_INCS :=
	FRAMEWORKS := \
		-lSDL2 \
		-lSDL2_image \
		-lSDL2_ttf
	FRAMEWORKSO := 

else ifeq ($(OS), Darwin)

	SDL_INCS := \
		-I./frameworks/SDL2.framework/Versions/A/Headers \
		-I./frameworks/SDL2_image.framework/Versions/A/Headers \
		-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
		-I./frameworks/SDL2_mixer.framework/Versions/A/Headers
	FRAMEWORKS := \
		-F./frameworks \
		-rpath ./frameworks \
		-framework SDL2 \
		-framework SDL2_ttf \
		-framework SDL2_image \
		-framework SDL2_mixer
	FRAMEWORKSO := \
		-F./frameworks

endif

PSO := $(addprefix $(SRCO), $(addsuffix .o, $(PSC)))
CHO := $(addprefix $(SRCO), $(addsuffix .o, $(CHC)))

all:		$(SRCO) $(LIB) $(PS) $(CH)

$(PS):	$(PSO) $(LIB)
	@$(CC) $^ $(INC) -o $(PS)
	@echo $(PS) "completed"

$(CH):	$(CHO) $(LIB)
	@$(CC) $^ $(INC) $(SDL_INCS) $(FRAMEWORKS) -o $(CH)
	@echo $(CH)" completed"

$(SRCO)grafic%.o:	$(SRC)grafic%.c
ifeq ($(OS), Linux)
	@$(CC) -MD -c $< $(INC) $(SDL_INCS) -o $@
else ifeq ($(OS), Darwin)
	@$(CC) -MD -c $< $(FRAMEWORKSO) $(INC) $(SDL_INCS) -o $@
endif

$(SRCO)%.o:	$(SRC)%.c
	@$(CC) -MD -c $< $(INC) -o $@

$(SRCO):
	@mkdir $@

$(LIB):
	@$(MAKE) -sC $(LIBD) all

clean:
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(SRCO)
	@echo "push_swap directory cleaning completed"

fclean:		clean
	@$(MAKE) -sC $(LIBD) fclean
	@rm -f $(PS) $(CH)
	@echo $(PS)" and "$(CH)" files deleted"

re:			fclean all

include $(wildcard $(SRCO)*.d)

.PHONY:		all clean fclean re
