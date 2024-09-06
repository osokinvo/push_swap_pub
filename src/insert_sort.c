/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:45:05 by ghusk             #+#    #+#             */
/*   Updated: 2020/04/04 16:21:22 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "stdio.h"

int sort3(t_storage *st)
{
	if (st->down_a && (st->down_a->n < st->top_a->n || st->down_a->n < st->top_a->next->n))
	{
		if (st->top_a->n > st->top_a->next->n)
		{
			write(1, "sa\n", 3);
			swap(&(st->top_a), &(st->down_a));
		}
		reverse_rotate(&(st->top_a), &(st->down_a), 1);
		write(1, "rra\n", 4);
		if (st->top_a->n > st->top_a->next->n)
		{
			write(1, "sa\n", 3);
			swap(&(st->top_a), &(st->down_a));
		}
	}
	else if (st->top_a && st->top_a->next && st->top_a->n > st->top_a->next->n)
		{
			write(1, "sa\n", 3);
			swap(&(st->top_a), &(st->down_a));
		}
	else
		return (0);
	return(1);
}

t_listi	*max_list(t_listi *head)
{
	t_listi	*max;

	max = head;
	while (head)
	{
		if (head->p_pos > max->p_pos)
		{
			max = head;
		}
		head = head->next;
	}
	return (max);
}

t_listi		*min_list(t_listi *head)
{
	t_listi *min;

	min = head;
	while (head)
	{
		if (head->p_pos < min->p_pos)
		{
			min = head;
		}
		head = head->next;
	}
	return (min);
}

void	take_max(t_storage *st, t_listi *max)
{
	if (max->pos - st->len_a <= st->len_b / 2)
		while (st->top_b != max)
		{
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
	else
		while (st->top_b != max)
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 3);
		}
	
}

void	take_smoll(t_storage *st, t_listi *min)
{
	t_listi *smoll;
	t_listi	*list;

	smoll = min;
	list = st->top_b;
	while (list)
	{
		if (list->p_pos < st->top_a->p_pos && list->p_pos > smoll->p_pos)
			smoll = list;
		list = list->next;
	}
	if (smoll->pos - st->len_a <= st->len_b / 2)
		while (st->top_b != smoll)
		{
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
	else
		while (st->top_b != smoll)
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
		}
}

void	go_insert(t_storage *st)
{
	t_listi *max;
	t_listi	*min;

	max = max_list(st->top_b);
	min = min_list(st->top_b);
	if (st->top_a->p_pos > max->p_pos || st->top_a->p_pos < min->p_pos)
	{
		take_max(st, max);
	}
	else 
		take_smoll(st, min);
	push_b(st);
	write(1, "pb\n", 3);
}

int		insert_sort(t_storage *st)
{
	if (st->len_a <= 3)
		sort3(st);
	else
	{
		push_b(st);
		write(1, "pb\n", 3);
		push_b(st);
		write(1, "pb\n", 3);
		while (st->len_a)
		{
			go_insert(st);
		}
		take_max(st, max_list(st->top_b));
		while (st->len_b)
		{
			push_a(st);
			write(1, "pa\n", 3);
		}
	}
	ft_free_storage(st);
	return (EXIT_SUCCESS);
}
