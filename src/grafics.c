/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:36:34 by val               #+#    #+#             */
/*   Updated: 2020/07/09 17:21:21 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	draw_screen(int pause, int screen_end, t_storage *st,
	t_grafic_storage *grafic_st)
{
	SDL_SetRenderDrawColor(grafic_st->renderer, 0x70, 0x80, 0x90, 0xFF);
	SDL_RenderClear(grafic_st->renderer);
	draw_head(pause, screen_end, grafic_st);
	draw_stack(st, grafic_st);
	draw_field_counter(grafic_st);
	SDL_RenderPresent(grafic_st->renderer);
}

static int	event_hendling(unsigned long time, int close_grafic, t_storage *st,
	t_grafic_storage *grafic_st)
{
	SDL_Event	e;
	int			pause;

	draw_screen(0, 0, st, grafic_st);
	pause = 0;
	while (!close_grafic && ((!grafic_st->result && ((SDL_GetTicks() - time)
		< TEMP_DELAY || (pause % 4))) || (grafic_st->result && ((SDL_GetTicks()
		- time) < TEMP_DELAY_RESULT || (pause % 4)))))
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				close_grafic = 1;
			else if (e.key.keysym.sym && e.key.keysym.sym == SDLK_SPACE)
				pause++;
		}
		draw_screen(pause, 0, st, grafic_st);
	}
	return (close_grafic);
}

static int	ft_match_input_func2(char *s, t_grafic_storage *grafic_st)
{
	if (!ft_strcmp(s, "rr"))
		(grafic_st->rr)++;
	else if (!ft_strcmp(s, "rra"))
		(grafic_st->rra)++;
	else if (!ft_strcmp(s, "rrb"))
		(grafic_st->rrb)++;
	else if (!ft_strcmp(s, "rrr"))
		(grafic_st->rrr)++;
	else if (*s == 0)
		grafic_st->result = 1;
	else if (!ft_strcmp(s, "Error"))
		return (1);
	return (0);
}

static int	ft_match_input_func(char *s, t_grafic_storage *grafic_st)
{
	if (!ft_strcmp(s, "sa"))
		(grafic_st->sa)++;
	else if (!ft_strcmp(s, "sb"))
		(grafic_st->sb)++;
	else if (!ft_strcmp(s, "ss"))
		(grafic_st->ss)++;
	else if (!ft_strcmp(s, "pa"))
		(grafic_st->pa)++;
	else if (!ft_strcmp(s, "pb"))
		(grafic_st->pb)++;
	else if (!ft_strcmp(s, "ra"))
		(grafic_st->ra)++;
	else if (!ft_strcmp(s, "rb"))
		(grafic_st->rb)++;
	else
		return (ft_match_input_func2(s, grafic_st));
	return (0);
}

int			ft_begin_grafics(t_storage *st, char *s)
{
	static t_grafic_storage	*grafic_st;
	static int				close_grafic;

	if (close_grafic == 0)
	{
		if (s == NULL)
		{
			if ((close_grafic = init(st, &grafic_st)))
				return (1);
		}
		else if ((close_grafic = ft_match_input_func(s, grafic_st)))
		{
			close_window(grafic_st, 1);
			return (1);
		}
		close_grafic = event_hendling(SDL_GetTicks(), close_grafic, st,
			grafic_st);
		if (grafic_st->result)
			close_grafic = 1;
		else
			draw_screen(0, 1, st, grafic_st);
		if (close_grafic)
			close_window(grafic_st, 1);
	}
	return (0);
}
