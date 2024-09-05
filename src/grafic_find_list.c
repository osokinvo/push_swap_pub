/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic_find_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:31:13 by val               #+#    #+#             */
/*   Updated: 2020/07/06 19:36:09 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	find_min(t_listi *list, t_grafic_storage *grafic_st)
{
	while (list)
	{
		if (list->p_pos < grafic_st->min_list->p_pos)
		{
			grafic_st->min_list = list;
		}
		list = list->next;
	}
}

void		find_min_list(t_storage *st, t_grafic_storage *grafic_st)
{
	if (st->len_a > 0)
	{
		grafic_st->min_list = st->top_a;
		find_min(grafic_st->min_list, grafic_st);
		if (st->len_b > 0)
		{
			find_min(st->top_b, grafic_st);
		}
	}
	else if (st->len_b > 0)
	{
		grafic_st->min_list = st->top_b;
		find_min(st->top_b, grafic_st);
	}
}

static void	find_max(t_listi *list, t_grafic_storage *grafic_st)
{
	while (list)
	{
		if (list->p_pos > grafic_st->max_list->p_pos)
		{
			grafic_st->max_list = list;
		}
		list = list->next;
	}
}

void		find_max_list(t_storage *st, t_grafic_storage *grafic_st)
{
	if (st->len_a > 0)
	{
		grafic_st->max_list = st->top_a;
		find_max(grafic_st->max_list, grafic_st);
		if (st->len_b > 0)
		{
			find_max(st->top_b, grafic_st);
		}
		find_min_list(st, grafic_st);
	}
	else if (st->len_b > 0)
	{
		grafic_st->max_list = st->top_b;
		find_max(grafic_st->max_list, grafic_st);
		find_min_list(st, grafic_st);
	}
	else
		grafic_st->max_list = NULL;
}
