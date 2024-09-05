/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:55:57 by val               #+#    #+#             */
/*   Updated: 2020/07/07 14:10:33 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void		draw_stack_b_one(t_listi *list, SDL_Rect *stack,
	t_grafic_storage *grafic_st)
{
	while (list)
	{
		if (list->p_pos == list->pos)
			SDL_SetRenderDrawColor(grafic_st->renderer, 0x32, 0xCD, 0x32,
				0xFF);
		else
			SDL_SetRenderDrawColor(grafic_st->renderer, 0xFF, 0x08, 0x08,
				0x08);
		stack->h = (grafic_st->list_h * list->p_pos) /
			grafic_st->max_list->p_pos + grafic_st->min_list_h;
		list = list->next;
		stack->y = grafic_st->y_stack - stack->h;
		SDL_RenderFillRect(grafic_st->renderer, stack);
		stack->x += grafic_st->width_stack;
	}
}

static t_listi	*draw_stack_b_many_stack2(t_listi *list, SDL_Rect *stack,
	t_grafic_storage *grafic_st)
{
	int	sum;
	int	red;
	int	i;

	sum = 0;
	red = 0;
	i = grafic_st->number_stack;
	while (list && i)
	{
		i--;
		if (i && list->next && list->p_pos < list->next->p_pos)
			red = 1;
		sum += list->p_pos;
		list = list->next;
	}
	if (red)
		SDL_SetRenderDrawColor(grafic_st->renderer, 0xFF, 0x08, 0x08, 0x08);
	else
		SDL_SetRenderDrawColor(grafic_st->renderer, 0x32, 0xCD, 0x32, 0xFF);
	stack->h = (int)((grafic_st->list_h * sum) / (grafic_st->max_list->p_pos *
		(grafic_st->number_stack - i))) + grafic_st->min_list_h;
	return (list);
}

static void		draw_stack_b_many_stack(t_storage *st, t_listi *list,
	SDL_Rect *stack, t_grafic_storage *grafic_st)
{
	int	k;
	int	n;

	k = grafic_st->width_a - grafic_st->width_stack * st->len_a;
	if (k)
		k = grafic_st->width_a / (k * grafic_st->number_stack);
	n = 0;
	while (list)
	{
		if (k)
		{
			n++;
			if ((n % k) == 0)
				stack->w = grafic_st->width_stack + 1;
			else
				stack->w = grafic_st->width_stack;
		}
		list = draw_stack_b_many_stack2(list, stack, grafic_st);
		stack->y = grafic_st->y_stack - stack->h;
		SDL_RenderFillRect(grafic_st->renderer, stack);
		stack->x += grafic_st->width_stack;
	}
}

void			draw_stack_b(t_storage *st, t_listi *list,
	t_grafic_storage *grafic_st)
{
	SDL_Rect	stack;

	stack.x = grafic_st->border.x + grafic_st->border.w - INDENTION -
		grafic_st->width_b;
	stack.w = grafic_st->width_stack;
	if (grafic_st->number_stack == 1)
		draw_stack_b_one(list, &stack, grafic_st);
	else
		draw_stack_b_many_stack(st, list, &stack, grafic_st);
	stack.x = SCREEN_WIDTH - BORDER - INDENTION - grafic_st->width_b;
	stack.y = grafic_st->y_stack;
	stack.w = grafic_st->width_b;
	stack.h = TEXT_HEIGTH;
	draw_text(&stack, "Stack B", grafic_st);
}
