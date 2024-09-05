/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:00:41 by val               #+#    #+#             */
/*   Updated: 2020/07/09 16:48:16 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void			set_default_values3(t_storage *st,
	t_grafic_storage *grafic_st)
{
	int width;

	grafic_st->number_stack = 0;
	grafic_st->width_stack = 0;
	width = grafic_st->border.x + grafic_st->border.w - 4 * INDENTION;
	while (grafic_st->width_stack == 0)
	{
		(grafic_st->number_stack)++;
		grafic_st->width_stack = (width * (grafic_st->number_stack)) /
		(st->len_a + st->len_b);
	}
	find_max_list(st, grafic_st);
	find_min_list(st, grafic_st);
	if (grafic_st->max_list)
	{
		grafic_st->list_h = grafic_st->border.h - HEIGTH_COUNTER - 2 *
			INDENTION - 2 * TEXT_HEIGTH;
		grafic_st->min_list_h = (grafic_st->list_h * grafic_st->min_list->p_pos)
			/ grafic_st->max_list->p_pos;
		if (grafic_st->min_list_h == 0)
			grafic_st->min_list_h = 1;
		grafic_st->list_h -= grafic_st->min_list_h;
	}
}

static void			set_default_values2(t_storage *st,
	t_grafic_storage *grafic_st)
{
	grafic_st->text_color.a = 0xFF;
	grafic_st->text_color.b = 0x00;
	grafic_st->text_color.g = 0x00;
	grafic_st->text_color.r = 0x00;
	grafic_st->sa = 0;
	grafic_st->sb = 0;
	grafic_st->ss = 0;
	grafic_st->pa = 0;
	grafic_st->pb = 0;
	grafic_st->ra = 0;
	grafic_st->rb = 0;
	grafic_st->rr = 0;
	grafic_st->rra = 0;
	grafic_st->rrb = 0;
	grafic_st->rrr = 0;
	grafic_st->result = 0;
	set_default_values3(st, grafic_st);
}

t_grafic_storage	*set_default_values(t_storage *st)
{
	t_grafic_storage *grafic_st;

	grafic_st = (t_grafic_storage *)malloc(sizeof(t_grafic_storage));
	if (grafic_st)
	{
		grafic_st->head.x = BORDER;
		grafic_st->head.y = BORDER;
		grafic_st->head.w = SCREEN_WIDTH - 2 * BORDER;
		grafic_st->head.h = HEIGTH_COUNTER / 3;
		grafic_st->field_counter.x = BORDER;
		grafic_st->field_counter.y = BORDER + grafic_st->head.h;
		grafic_st->field_counter.w = grafic_st->head.w;
		grafic_st->field_counter.h = HEIGTH_COUNTER;
		grafic_st->border.x = BORDER;
		grafic_st->border.y = grafic_st->field_counter.y + HEIGTH_COUNTER;
		grafic_st->border.w = grafic_st->head.w;
		grafic_st->border.h = SCREEN_HEIGTH - BORDER - grafic_st->border.y;
		grafic_st->y_stack = grafic_st->border.y + grafic_st->border.h -
			INDENTION - TEXT_HEIGTH;
		set_default_values2(st, grafic_st);
	}
	return (grafic_st);
}
