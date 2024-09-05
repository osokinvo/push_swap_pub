/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_field_counter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:49:24 by val               #+#    #+#             */
/*   Updated: 2020/07/09 16:29:55 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	draw_oper(int i, char *oper, SDL_Rect *field,
	t_grafic_storage *grafic_st)
{
	char	*str;
	char	*num;

	num = ft_itoa(i);
	str = ft_strjoin(oper, num);
	if (num)
		free(num);
	if (str)
	{
		draw_text(field, str, grafic_st);
		free(str);
	}
}

static void	draw_field_counter2(SDL_Rect field, int step_w, int step_h,
	t_grafic_storage *grafic_st)
{
	field.x += step_w;
	field.y = grafic_st->field_counter.y + INDENTION;
	draw_oper(grafic_st->sa, "swap a: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->sb, "swap b: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->ss, "ss a: ", &field, grafic_st);
	field.x += step_w;
	field.y = grafic_st->field_counter.y + INDENTION;
	draw_oper(grafic_st->ra, "rotete a: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->rb, "rotete b: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->rr, "rr: ", &field, grafic_st);
	field.x += step_w;
	field.y = grafic_st->field_counter.y + INDENTION;
	draw_oper(grafic_st->rra, "reverse rotete a: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->rrb, "reverse rotete b: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->rrr, "rrr: ", &field, grafic_st);
}

void		draw_field_counter(t_grafic_storage *grafic_st)
{
	SDL_Rect	field;
	int			step_w;
	int			step_h;

	SDL_SetRenderDrawColor(grafic_st->renderer, 0xD3, 0xD3, 0xD3, 0xFF);
	SDL_RenderFillRect(grafic_st->renderer, &(grafic_st->field_counter));
	step_w = (grafic_st->field_counter.w - 2 * INDENTION) / 4;
	step_h = (grafic_st->field_counter.h - 2 * INDENTION) / 4;
	field.w = 0;
	field.h = step_h;
	field.x = grafic_st->field_counter.x + INDENTION;
	field.y = grafic_st->field_counter.y + INDENTION;
	draw_oper(grafic_st->pa + grafic_st->pb + grafic_st->sa + grafic_st->sb +
		grafic_st->ss + grafic_st->ra + grafic_st->rb + grafic_st->rr +
		grafic_st->rra + grafic_st->rrb + grafic_st->rrr, "Total: ", &field,
		grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->pa, "push a: ", &field, grafic_st);
	field.y += step_h;
	draw_oper(grafic_st->pb, "push b: ", &field, grafic_st);
	draw_field_counter2(field, step_w, step_h, grafic_st);
}
