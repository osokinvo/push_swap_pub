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

PSS := push_swap_smart
PSQ := push_swap_qsort
PSI := push_swap_insert
PSM := push_swap_merge
CH := checker
CC := gcc -g -Wall -Wextra -Werror
LIBD := libft/
LIB := $(LIBD)libft.a
PSSC :=	blocks\
		error\
		finder\
		ft_checker2\
		ft_listi\
		ft_push_swap_smart\
		funcsh\
		smart_sort\

PSQC :=	error\
		finder\
		ft_listi\
		ft_push_swap_qsort\
		quick_sort\
		funcsh\

PSIC :=	error\
		finder\
		ft_listi\
		ft_push_swap_insert\
		insert_sort\
		funcsh\

PSMC :=	error\
		finder\
		ft_listi\
		ft_push_swap_merge\
		merge_sort\
		funcsh\

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

PSSO := $(addprefix $(SRCO), $(addsuffix .o, $(PSSC)))
PSQO := $(addprefix $(SRCO), $(addsuffix .o, $(PSQC)))
PSIO := $(addprefix $(SRCO), $(addsuffix .o, $(PSIC)))
PSMO := $(addprefix $(SRCO), $(addsuffix .o, $(PSMC)))
CHO := $(addprefix $(SRCO), $(addsuffix .o, $(CHC)))

all:		$(SRCO) $(LIB) $(PSS) $(PSQ) $(PSI) $(PSM) $(CH)

$(PSS):	$(PSSO) $(LIB)
	@$(CC) $^ $(INC) -o $(PSS)
	@echo $(PSS) "completed"

$(PSQ):	$(PSQO) $(LIB)
	@$(CC) $^ $(INC) -o $(PSQ)
	@echo $(PSQ) "completed"

$(PSI):	$(PSIO) $(LIB)
	@$(CC) $^ $(INC) -o $(PSI)
	@echo $(PSI) "completed"

$(PSM):	$(PSMO) $(LIB)
	@$(CC) $^ $(INC) -o $(PSM)
	@echo $(PSM) "completed"

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
	@rm -f $(PSS) $(PSQ) $(PSI) $(PSM) $(CH)
	@echo $(PSS) $(PSQ) $(PSI) $(PSM)" and "$(CH)" files deleted"

re:			fclean all

include $(wildcard $(SRCO)*.d)

.PHONY:		all clean fclean re
