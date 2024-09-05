/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:45:05 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/06 20:06:56 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		sort3(t_storage *st)
{
	if (st->down_a && (st->down_a->n < st->top_a->n || st->down_a->n <
		st->top_a->next->n))
	{
		if (st->top_a->n > st->top_a->next->n)
		{
			swap(&(st->top_a), &(st->down_a));
			write(1, "sa\n", 3);
		}
		reverse_rotate(&(st->top_a), &(st->down_a), 1);
		write(1, "rra\n", 4);
		if (st->top_a->n > st->top_a->next->n)
		{
			swap(&(st->top_a), &(st->down_a));
			write(1, "sa\n", 3);
		}
	}
	else if (st->top_a && st->top_a->next && st->top_a->n > st->top_a->next->n)
	{
		swap(&(st->top_a), &(st->down_a));
		write(1, "sa\n", 3);
	}
	else
		return (0);
	return (1);
}

t_listi	*find_list_max(t_listi *list)
{
	int		p_pos_max;
	t_listi	*result;

	p_pos_max = list->p_pos;
	result = list;
	while (list)
	{
		if (list->p_pos > p_pos_max)
		{
			p_pos_max = list->p_pos;
			result = list;
		}
		list = list->next;
	}
	return (result);
}

void	push_a_in_sort4(t_storage *st, t_listi *list_max)
{
	if (st->top_a->p_pos < list_max->p_pos - 1)
	{
		rotate(&(st->top_a), &(st->down_a), 1);
		write(1, "ra\n", 3);
	}
	push_a(st);
	write(1, "pa\n", 3);
}

void	find_max_block(t_storage *st, t_listi *list_max, int k)
{
	while (st->top_b != list_max)
	{
		if (st->top_b->p_pos > k)
		{
			push_a_in_sort4(st, list_max);
		}
		else if (st->len_b - list_max->pos <= list_max->pos)
		{
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
		}
	}
}

int		smart_sort(t_storage *st)
{
	t_listi	*list_max;

	if (!ft_stack_is_sort(st, 0))
	{
		if (st->len_a <= 3)
			sort3(st);
		else
		{
			blocks(st, st->len_a / 2, st->len_a);
			sort3(st);
			list_max = find_list_max(st->top_b);
			while (st->len_b)
			{
				find_max_block(st, list_max, list_max->p_pos - 4);
				push_a_in_sort4(st, list_max);
				while (sort3(st))
					;
				if (st->len_b)
					list_max = find_list_max(st->top_b);
			}
		}
	}
	ft_free_storage(st);
	return (EXIT_SUCCESS);
}
