/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_draw_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:48:19 by val               #+#    #+#             */
/*   Updated: 2020/07/09 16:23:51 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	draw_head(int pause, int screen_end, t_grafic_storage *grafic_st)
{
	SDL_SetRenderDrawColor(grafic_st->renderer, 0xD3, 0xD3, 0xD3, 0xFF);
	SDL_RenderFillRect(grafic_st->renderer, &(grafic_st->head));
	if (pause % 4)
	{
		draw_text(&(grafic_st->head), "PAUSE", grafic_st);
	}
	else if (screen_end)
	{
		draw_text(&(grafic_st->head), "Please enter the following operation",
			grafic_st);
	}
	else if (grafic_st->result)
	{
		draw_text(&(grafic_st->head), "Result", grafic_st);
	}
}
