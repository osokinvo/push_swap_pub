/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:32:33 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/06 19:31:41 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <limits.h>
#include <stdio.h>

static void	sort_p_pos(t_storage *st)
{
	int		min;
	int		p_min;
	int		counter;
	t_listi *list;
	t_listi	*l_min;

	counter = 0;
	min = INT_MIN;
	while (counter != st->len_a)
	{
		p_min = INT_MAX;
		list = st->top_a;
		while (list)
		{
			if (list->n <= p_min && list->n >= min)
			{
				l_min = list;
				p_min = list->n;
			}
			list = list->next;
		}
		l_min->p_pos = ++counter;
		min = p_min + 1;
	}
}

void		main_func(t_storage *storage)
{
	t_listi	*list;
	int		len;

	len = 0;
	list = storage->top_a;
	while (list)
	{
		len++;
		list->pos = len;
		list = list->next;
	}
	storage->len_a = len;
	sort_p_pos(storage);
	list = storage->top_a;
	while (list->next)
		list = list->next;
	if (list != storage->top_a)
		storage->down_a = list;
}
