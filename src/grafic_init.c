/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:56:16 by val               #+#    #+#             */
/*   Updated: 2020/07/09 17:19:40 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static int	check_screen_param(void)
{
	if (SCREEN_WIDTH < 600 || SCREEN_HEIGTH < 600)
		return (1);
	if (BORDER < 0 || INDENTION < 0 || HEIGTH_COUNTER < 0 || TEMP_DELAY < 0
		|| TEMP_DELAY_RESULT < 30)
		return (1);
	if (SCREEN_WIDTH < 3 * BORDER + 6 * INDENTION)
		return (1);
	if (SCREEN_HEIGTH < 3 * BORDER || SCREEN_WIDTH < 6 * INDENTION +
		HEIGTH_COUNTER + 2 * TEXT_HEIGTH)
		return (1);
	if (TEXT_HEIGTH < 10)
		return (1);
	if (HEIGTH_COUNTER < 3 * TEXT_HEIGTH + 2 * INDENTION)
		return (1);
	return (0);
}

static int	check_screen_param2(void)
{
	SDL_DisplayMode	current;
	int				should_be_zero;

	if ((should_be_zero = SDL_GetCurrentDisplayMode(0, &current)) != 0)
	{
		SDL_Quit();
		return (1);
	}
	if (SCREEN_HEIGTH > current.h)
	{
		SDL_Quit();
		return (1);
	}
	if (SCREEN_WIDTH > current.w)
	{
		SDL_Quit();
		return (1);
	}
	return (0);
}

void		close_window(t_grafic_storage *grafic_st, int all)
{
	if (all)
	{
		TTF_CloseFont(grafic_st->font);
		TTF_Quit();
		SDL_DestroyRenderer(grafic_st->renderer);
	}
	SDL_DestroyWindow(grafic_st->window);
	free(grafic_st);
	SDL_Quit();
}

static int	init2(t_grafic_storage **grafic_st)
{
	(*grafic_st)->renderer = SDL_CreateRenderer((*grafic_st)->window, -1,
		SDL_RENDERER_ACCELERATED);
	if ((*grafic_st)->renderer == NULL)
	{
		close_window(*grafic_st, 0);
		return (1);
	}
	if (TTF_Init() == -1)
	{
		SDL_DestroyRenderer((*grafic_st)->renderer);
		close_window(*grafic_st, 0);
		return (1);
	}
	(*grafic_st)->font = TTF_OpenFont("./bonus/Arial.ttf", TEXT_HEIGTH);
	if ((*grafic_st)->font == NULL)
	{
		SDL_DestroyRenderer((*grafic_st)->renderer);
		TTF_Quit();
		close_window(*grafic_st, 0);
		return (1);
	}
	return (0);
}

int			init(t_storage *st, t_grafic_storage **grafic_st)
{
	if (check_screen_param() || SDL_Init(SDL_INIT_VIDEO) < 0)
		return (1);
	if (check_screen_param2() ||
		!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		SDL_Quit();
		return (1);
	}
	(*grafic_st) = set_default_values(st);
	if ((*grafic_st) == NULL)
	{
		SDL_Quit();
		return (1);
	}
	(*grafic_st)->window = SDL_CreateWindow("Push_swap_grafic",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
		SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
	if ((*grafic_st)->window == NULL)
	{
		SDL_Quit();
		free((*grafic_st));
		return (1);
	}
	return (init2(grafic_st));
}
