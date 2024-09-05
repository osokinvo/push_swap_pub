/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 10:28:53 by val               #+#    #+#             */
/*   Updated: 2020/07/06 19:35:43 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sqrt(int nb)
{
	int result;
	int value;

	result = 1;
	value = 1;
	if (nb > 0 && nb < 2147395601)
		while (result < 46341)
		{
			if (value >= nb)
				return (result);
			result++;
			value = result * result;
		}
	return (0);
}

static int	optim_push_b(t_storage *st, int mid, int tm, int dm)
{
	if (st->top_a->p_pos <= mid && st->top_a->p_pos > tm)
	{
		push_b(st);
		write(1, "pb\n", 3);
		if (st->len_b > 1)
		{
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
	}
	else if (st->top_a->p_pos > mid && st->top_a->p_pos <= dm)
	{
		push_b(st);
		write(1, "pb\n", 3);
	}
	else
	{
		rotate(&(st->top_a), &(st->down_a), 1);
		write(1, "ra\n", 3);
		return (0);
	}
	return (1);
}

static int	init_border(int *tm, int *dm, int len, int block)
{
	int	n;

	if ((*tm) - block < 0)
	{
		n = (*tm);
		(*tm) = 0;
	}
	else
	{
		(*tm) -= block;
		n = block;
	}
	if ((*dm) + block > len - 3)
	{
		n += len - 3 - (*dm);
		(*dm) = len - 3;
	}
	else
	{
		n += block;
		(*dm) += block;
	}
	return (n);
}

void		blocks(t_storage *st, int mid, int len)
{
	int	n;
	int tm;
	int	dm;
	int block;

	tm = mid;
	dm = mid;
	block = len / (ft_sqrt(len) / 2);
	while (st->len_a > 3)
	{
		n = init_border(&tm, &dm, len, block);
		while (n)
		{
			n -= optim_push_b(st, mid, tm, dm);
		}
	}
}
