/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_draw_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:58:02 by val               #+#    #+#             */
/*   Updated: 2020/07/06 19:34:13 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	set_alig(SDL_Rect *field, SDL_Rect *text_field)
{
	if (field->x + text_field->w > SCREEN_WIDTH - BORDER)
		text_field->x = SCREEN_WIDTH - BORDER - text_field->w;
	else if (field->w - text_field->w <= 1)
		text_field->x = field->x;
	else
		text_field->x = field->x + (field->w - text_field->w) / 2;
	if (field->h - text_field->h <= 1)
		text_field->y = field->y;
	else
		text_field->y = field->y + (field->h - text_field->h) / 2;
}

void		draw_text(SDL_Rect *field, char *str, t_grafic_storage *grafic_st)
{
	SDL_Texture	*texture;
	SDL_Surface	*surface;
	SDL_Rect	text_field;

	surface = TTF_RenderText_Blended(grafic_st->font, str,
		grafic_st->text_color);
	if (surface)
	{
		texture = SDL_CreateTextureFromSurface(grafic_st->renderer, surface);
		if (texture)
		{
			text_field.h = surface->h;
			text_field.w = surface->w;
			SDL_FreeSurface(surface);
			set_alig(field, &text_field);
			SDL_RenderCopyEx(grafic_st->renderer, texture, NULL, &text_field,
				0, NULL, SDL_FLIP_NONE);
			SDL_DestroyTexture(texture);
		}
	}
}
