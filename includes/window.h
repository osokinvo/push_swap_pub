/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:59:57 by val               #+#    #+#             */
/*   Updated: 2020/07/09 17:23:49 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

/*
**	Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
*/

# if defined(__linux__)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_render.h>

/*
**	Apple OSX and iOS (Darwin)
*/

# elif defined(__APPLE__)
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#  include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"
#  include "../frameworks/SDL2_mixer.framework/Headers/SDL_mixer.h"
#  include "../frameworks/SDL2.framework/Headers/SDL_render.h"

# endif

# include "ft_listi.h"
# include "libft.h"

typedef	struct		s_grafic_storage
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Rect		border;
	SDL_Rect		field_counter;
	SDL_Rect		head;
	TTF_Font		*font;
	SDL_Color		text_color;
	t_listi			*min_list;
	t_listi			*max_list;
	int				list_h;
	int				min_list_h;
	int				width_stack;
	int				number_stack;
	int				width_a;
	int				width_b;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				y_stack;
	int				result;
}					t_grafic_storage;

# define SCREEN_WIDTH 600
# define SCREEN_HEIGTH 600
# define BORDER 10
# define INDENTION 3
# define HEIGTH_COUNTER 50
# define TEXT_HEIGTH 14

# define TEMP_DELAY 3
# define TEMP_DELAY_RESULT 5000

/*
**	grafic_init
*/

int					init(t_storage *st, t_grafic_storage **grafic_st);
void				close_window(t_grafic_storage *grafic_st, int all);

/*
**	grafic_storage
*/

t_grafic_storage	*set_default_values(t_storage *st);

/*
**	grafic_stack
*/

void				draw_stack(t_storage *st, t_grafic_storage *grafic_st);

/*
**	grafic_stack_b
*/

void				draw_stack_b(t_storage *st, t_listi *list,
						t_grafic_storage *grafic_st);

/*
**	grafic_draw_text
*/

void				draw_text(SDL_Rect *field, char *str,
						t_grafic_storage *grafic_st);

/*
**	grafic_find_list
*/

void				find_min_list(t_storage *st, t_grafic_storage *grafic_st);
void				find_max_list(t_storage *st, t_grafic_storage *grafic_st);

/*
**	grafic_draw_head
*/

void				draw_head(int pause, int screen_end,
						t_grafic_storage *grafic_st);

/*
**	grafic_field_counter
*/

void				draw_field_counter(t_grafic_storage *grafic_st);

#endif
