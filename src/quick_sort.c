/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:45:05 by ghusk             #+#    #+#             */
/*   Updated: 2020/04/03 19:44:15 by val              ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	return(EXIT_FAILURE);
}

int find_max_list(t_listi *list, int k)
{
	int	p_pos_max;

	p_pos_max = list->p_pos;
	while(k--)
	{
		if (list->p_pos > p_pos_max)
		{
			p_pos_max = list->p_pos;
		}
		list = list->next;
	}
	return (p_pos_max);
}

int middel(t_listi *list, int k)
{
	float	result;
	int		i;

	i = k;
	result = 0;
	while (i--)
	{
		result = result + (float)(list->p_pos);
		list = list->next;
	}
	return ((int)(result / k));
}

int		push_count(int k, int i)
{
	int result;

	result = k / 2;
	if (i)
	{
		if (!(k % 2))
			result--;
	}
	else
		result++;
	return (result);
}

void	to_a(t_storage *st, int k)
{
	int i;
	int	j;
	int	mid;

	if (k < 5)
	{
		i = find_max_list(st->top_b, k);
		while (k--)
		{
			push_a(st);
			write(1, "pa\n", 3);
			if (st->top_a->p_pos < i - 1)
			{
				rotate(&(st->top_a), &(st->down_a), 1);
				write(1, "ra\n", 3);
			}
		}
		sort3(st);
		if (st->down_a->p_pos < (i - 1))
			sort3(st);
		return ;
	}
		mid = middel(st->top_b, k);
		i = 0;
		j = push_count(k, 0);
		while (j)
		{
			if (st->top_b->p_pos >= mid)
			{
				write(1, "pa\n", 3);
				push_a(st);
				j--;
			}
			else
			{
				rotate(&(st->top_b), &(st->down_b), 1);
				write(1, "rb\n", 3);
				i++;
			}
		}
		j = push_count(k, 0);
		k = k - j;
			while (i--)
			{
				write(1, "rrb\n", 4);
				reverse_rotate(&(st->top_b), &(st->down_b), -1);
			}
	if (j > 1)
		to_b(st, j, 1);
	if (k)
	{
		to_a(st, k);
	}
}

void	to_b(t_storage *st, int k, int sort)
{
	int i;
	int	j;
	int	mid;

	mid = middel(st->top_a, k);
	i = 0;
	j = 0;
	if (k > 2)
	{
		j = push_count(k, 1);
		while (j)
		{
			if (st->top_a->p_pos < mid)
			{
				write(1, "pb\n", 3);
				push_b(st);
				j--;
			}
			else
			{
				rotate(&(st->top_a), &(st->down_a), 1);
				write(1, "ra\n", 3);
				i++;
			}
		}
		j = push_count(k, 1);
		k = k - j;
		if (sort)
		{
			while (i--)
			{
				write(1, "rra\n", 4);
				reverse_rotate(&(st->top_a), &(st->down_a), 1);
			}
		}
	}
	if (k == 2 && st->top_a->p_pos > st->top_a->next->p_pos)
	{
		write(1, "sa\n", 3);
		swap(&(st->top_a), &(st->down_a));
	}
	if (k > 2)
		to_b(st, k, sort);
	if (j)
	{
	to_a(st, j);
	}
}

int		quick_sort(t_storage *st)
{
	if (st->len_a <= 3)
		sort3(st);
	else
	{
		to_b(st, st->len_a, 0);
	}
	ft_free_storage(st);
	return (EXIT_SUCCESS);
}
