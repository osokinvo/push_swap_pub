/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:20:16 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/06 19:36:35 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_listi.h"

void	swap(t_listi **top, t_listi **down)
{
	int		pos;
	t_listi	*mid;

	if (!(*top) ||
	!(mid = (*top)->next))
		return ;
	pos = (*top)->pos;
	(*top)->pos = mid->pos;
	mid->pos = pos;
	(*top)->next = mid->next;
	mid->next = (*top);
	if (mid == *down)
	{
		*down = *top;
	}
	*top = mid;
}

void	push_a(t_storage *store)
{
	t_listi *tmp;

	if (store->top_b)
	{
		(store->len_a)++;
		(store->len_b)--;
		if (store->top_a && !(store->down_a))
			store->down_a = store->top_a;
		tmp = store->top_b;
		store->top_b = tmp->next;
		tmp->next = store->top_a;
		store->top_a = tmp;
		if (store->down_b == store->top_b)
			store->down_b = NULL;
	}
}

void	push_b(t_storage *store)
{
	t_listi *tmp;

	if (store->top_a)
	{
		(store->len_b)++;
		(store->len_a)--;
		if (store->top_b && !(store->down_b))
			store->down_b = store->top_b;
		tmp = store->top_a;
		store->top_a = tmp->next;
		tmp->next = store->top_b;
		store->top_b = tmp;
		if (store->down_a == store->top_a)
			store->down_a = NULL;
	}
}

void	rotate(t_listi **top, t_listi **down, int sort)
{
	t_listi	*last;

	if (!(*top) || !(last = (*top)->next))
		return ;
	while (last)
	{
		(last->pos) -= sort;
		last = last->next;
	}
	(*down)->next = *top;
	(*top)->pos = (*down)->pos + sort;
	*down = *top;
	*top = ((*top)->next);
	(*down)->next = NULL;
}

void	reverse_rotate(t_listi **top, t_listi **down, int sort)
{
	t_listi	*last;

	if (!(*top) || !((*top)->next))
		return ;
	last = *top;
	(*down)->pos = (*top)->pos;
	while (last->next != *down)
	{
		(last->pos) += sort;
		last = last->next;
	}
	(last->pos) += sort;
	(*down)->next = *top;
	last->next = NULL;
	*top = *down;
	*down = last;
}
