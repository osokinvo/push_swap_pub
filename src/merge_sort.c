/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:45:05 by ghusk             #+#    #+#             */
/*   Updated: 2020/04/04 13:38:54 by val              ###   ########.fr       */
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

// void	block(t_storage *st)
// {
// 	if (st->da)
// 		st->da_block = st->down_a->block + 1;
// 	if (st->tb)
// 		st->tb_block = st->top_b->block + 1;
// 	if (st->db)
// 	{
// 		if (!st->down_b && !st->tb)
// 		{
// 			st->db_block = st->top_b->block + 1;
// 		}
// 		else
// 		{
// 			st->db_block = st->down_b->block + 1;
// 		}
// 	}
// }

// void	move_m(t_storage *st, int case_m)
// {
// 	if (case_m == 1)
// 	{
// 		reverse_rotate(&(st->top_a), &(st->down_a), 1);
// 		write(1, "rra\n", 4);
// 		st->da_block = st->top_a->block;
// 		(st->da)--;
// 		(st->ta)++;
// 	}
// 	else if (case_m == 2)
// 	{
// 		push_a(st);
// 		write(1, "pa\n", 3);
// 		st->tb_block = st->top_a->block;
// 		(st->tb)--;
// 		(st->ta)++;
// 	}
// 	else if (case_m == 3)
// 	{
// 		reverse_rotate(&(st->top_b), &(st->down_b), -1);
// 		write(1, "rrb\n", 4);
// 		push_a(st);
// 		write(1, "pa\n", 3);
// 		st->db_block = st->top_a->block;
// 		(st->db)--;
// 		(st->ta)++;
// 	}
// }

// void	block_m(t_storage *st)
// {
// 	block(st);
// 	while (st->tb_block || st->da_block || st->db_block)
// 	{
// 		if (st->tb_block && (!(st->da_block) || st->top_b->p_pos > st->down_a->p_pos))
// 		{
// 			if (st->db_block && st->down_b->p_pos > st->top_b->p_pos)
// 			{
// 				move_m(st, 3);
// 			}
// 			else
// 			{
// 				move_m(st, 2);
// 			}
// 		}
// 		else if (st->da_block)
// 		{
// 			if (st->db_block && !(st->down_b) && !(st->tb) && st->top_b && st->top_b->p_pos > st->down_a->p_pos)
// 			{
// 				push_a(st);
// 				write(1, "pa\n", 3);
// 				st->db_block = st->top_a->block;
// 				(st->db)--;
// 				(st->ta)++;
// 			}
// 			else if (st->db_block && st->down_b && st->down_b->p_pos > st->down_a->p_pos)
// 			{
// 				move_m(st, 3);
// 			}
// 			else
// 			{
// 				move_m(st, 1);
// 			}
// 		}
// 		else if (st->db_block)
// 		{
// 			move_m(st, 3);
// 		}
// 	}
// }

// void	move_p(t_storage *st, int case_block)
// {
// 	int	i;

// 	i = 0;
// 	if (case_block == 2)
// 	{
// 		(st->ta) -= st->da_block;
// 		(st->da) += st->da_block;
// 		while (i < st->da_block)
// 		{
// 			rotate(&(st->top_a), &(st->down_a), -1);
// 			write(1, "ra\n", 3);
// 			st->down_a->block = i++;
// 		}
// 	}
// 	else if (case_block == 1)
// 	{
// 		(st->ta) -= st->tb_block;
// 		(st->tb) += st->tb_block;
// 		while (i < st->tb_block)
// 		{
// 			push_b(st);
// 			write(1, "pb\n", 3);
// 			st->top_b->block = i++;
// 		}
// 	}
// 	else if (case_block == 3)
// 	{
// 		(st->ta) -= st->db_block;
// 		(st->db) += st->db_block;
// 		while (i < st->db_block)
// 		{
// 			push_b(st);
// 			write(1, "pb\n", 3);
// 			rotate(&(st->top_b), &(st->down_b), -1);
// 			write(1, "rb\n", 3);
// 			st->down_b->block = i++;
// 		}
// 	}
// }

// void	block_p(t_storage *st)
// {
// 	if (st->ta <= st->block || !(st->block))
// 		return ;
// 	while (st->ta)
// 	{
// 		if (st->ta % st->block)
// 			st->tb_block = st->ta % st->block;
// 		else
// 			st->tb_block = st->block;
// 		move_p(st, 1);
// 		if (st->ta)
// 		{
// 			st->da_block = st->block;
// 			move_p(st, 2);
// 			if (st->ta)
// 			{
// 				st->db_block = st->block;
// 				move_p(st, 3);
// 			}
// 		}
// 	}
// 	while (st->da || st->tb || st->db)
// 		block_m(st);
// 	(st->block) *= 3;
// 	block_p(st);
// }

// int		merge_sort(t_storage *st)
// {
// 	if (st->len_a <= 3)
// 		sort3(st);
// 	else
// 	{
// 		st->ta = st->len_a;
// 		st->block = 1;
// 		block_p(st);
// 	}
// 	ft_free_storage(st);
// 	return (EXIT_SUCCESS);
// }

void	sent_posit_b(t_storage *st)
{
	int min;
	int top_val;
	int next_val;
	int down_val;

	if (st->top_a->p_pos > st->down_a->p_pos)
	{
		if (st->top_a->next->p_pos < st->down_a->p_pos)
		{
			swap(&(st->top_a), &(st->down_a));
			write(1, "sa\n", 3);
		}
		else
		{
			reverse_rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "rra\n", 4);
		}
	}
	push_b(st);
	write(1, "pb\n", 3);
	while (st->down_a)
	{
		min = st->top_b->p_pos;
		top_val = st->top_a->p_pos;
		next_val = st->top_a->next->p_pos;
		down_val = st->down_a->p_pos;
		if (top_val > min)
		{
			if (next_val > min)
			{
				if (down_val > min)
				{
					if (top_val < next_val)
					{
						if (down_val < top_val)
						{
							reverse_rotate(&(st->top_a), &(st->down_a), -1);
							write(1, "rra\n", 4);
						}
					}
					else
					{
						if (next_val < down_val)
						{
							swap(&(st->top_a), &(st->down_a));
							write(1, "sa\n", 3);
						}
						else
						{
							reverse_rotate(&(st->top_a), &(st->down_a), -1);
							write(1, "rra\n", 4);
						}
					}
				}
				else
				{
					if (next_val < top_val)
					{
						swap(&(st->top_a), &(st->down_a));
						write(1, "sa\n", 3);
					}
				}
			}
			else
			{
				if (down_val > min)
				{
					if (down_val < top_val)
					{
						reverse_rotate(&(st->top_a), &(st->down_a), -1);
						write(1, "rra\n", 4);
					}
				}
			}
			push_b(st);
			write(1, "pb\n", 3);
		}
		else if (next_val > min)
		{
			if (down_val > min)
			{
				if (next_val < down_val)
				{
					swap(&(st->top_a), &(st->down_a));
					write(1, "sa\n", 3);
				}
				else
				{
					reverse_rotate(&(st->top_a), &(st->down_a), -1);
					write(1, "rra\n", 4);
				}
			}
			else
			{
				swap(&(st->top_a), &(st->down_a));
				write(1, "sa\n", 3);
			}
			push_b(st);
			write(1, "pb\n", 3);
		}
		else if (down_val > min)
		{
			reverse_rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "rra\n", 4);
			push_b(st);
			write(1, "pb\n", 3);
		}
		else
			return ;
	}
	push_b(st);
	write(1, "pb\n", 3);
	if (st->top_b->p_pos < st->top_b->next->p_pos)
	{
		rotate(&(st->top_b), &(st->down_b), -1);
		write(1, "rb\n", 3);
	}
}

void	sent_neg_b(t_storage *st)
{
	int min;
	int top_val;
	int next_val;
	int down_val;

	if (st->top_a->p_pos > st->down_a->p_pos)
	{
		if (st->top_a->next->p_pos < st->down_a->p_pos)
		{
			swap(&(st->top_a), &(st->down_a));
			write(1, "sa\n", 3);
		}
		else
		{
			reverse_rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "rra\n", 4);
		}
	}
	push_b(st);
	write(1, "pb\n", 3);
	min = st->top_b->p_pos;
	rotate(&(st->top_b), &(st->down_b), -1);
	write(1, "rb\n", 3);
	while (st->down_a)
	{
		top_val = st->top_a->p_pos;
		next_val = st->top_a->next->p_pos;
		down_val = st->down_a->p_pos;
		if (top_val > min)
		{
			if (next_val > min)
			{
				if (down_val > min)
				{
					if (top_val < next_val)
					{
						if (down_val < top_val)
						{
							reverse_rotate(&(st->top_a), &(st->down_a), -1);
							write(1, "rra\n", 4);
						}
					}
					else
					{
						if (next_val < down_val)
						{
							swap(&(st->top_a), &(st->down_a));
							write(1, "sa\n", 3);
						}
						else
						{
							reverse_rotate(&(st->top_a), &(st->down_a), -1);
							write(1, "rra\n", 4);
						}
					}
				}
				else
				{
					if (next_val < top_val)
					{
						swap(&(st->top_a), &(st->down_a));
						write(1, "sa\n", 3);
					}
				}
			}
			else
			{
				if (down_val > min)
				{
					if (down_val < top_val)
					{
						reverse_rotate(&(st->top_a), &(st->down_a), -1);
						write(1, "rra\n", 4);
					}
				}
			}
			push_b(st);
			write(1, "pb\n", 3);
			min = st->top_b->p_pos;
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
		else if (next_val > min)
		{
			if (down_val > min)
			{
				if (next_val < down_val)
				{
					swap(&(st->top_a), &(st->down_a));
					write(1, "sa\n", 3);
				}
				else
				{
					reverse_rotate(&(st->top_a), &(st->down_a), -1);
					write(1, "rra\n", 4);
				}
			}
			else
			{
				swap(&(st->top_a), &(st->down_a));
				write(1, "sa\n", 3);
			}
			push_b(st);
			write(1, "pb\n", 3);
			min = st->top_b->p_pos;
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
		else if (down_val > min)
		{
			reverse_rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "rra\n", 4);
			push_b(st);
			write(1, "pb\n", 3);
			min = st->top_b->p_pos;
			rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rb\n", 3);
		}
		else
			return ;
	}
	push_b(st);
	write(1, "pb\n", 3);
	if (st->top_b->p_pos > st->down_b->p_pos)
	{
		rotate(&(st->top_b), &(st->down_b), -1);
		write(1, "rb\n", 3);
	}
}

void	sent_posit_a(t_storage *st)
{
	int max;
	int top_val;
	int next_val;
	int down_val;

	top_val = st->top_b->p_pos;
	next_val = st->top_b->next->p_pos;
	down_val = st->down_b->p_pos;
	if (down_val > top_val)
	{
		if (next_val > down_val)
		{
			swap(&(st->top_b), &(st->down_b));
			write(1, "sb\n", 3);
		}
		else
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
		}
	}
	push_a(st);
	write(1, "pa\n", 3);
	while (st->down_b)
	{
		max= st->top_a->p_pos;
		top_val = st->top_b->p_pos;
		next_val = st->top_b->next->p_pos;
		down_val = st->down_b->p_pos;
		if (top_val < max)
		{
			if (next_val < max)
			{
				if (down_val < max)
				{
					if (top_val > next_val)
					{
						if (down_val > top_val)
						{
							reverse_rotate(&(st->top_b), &(st->down_b), -1);
							write(1, "rrb\n", 4);
						}
					}
					else
					{
						if (next_val > down_val)
						{
							swap(&(st->top_b), &(st->down_b));
							write(1, "sb\n", 3);
						}
						else
						{
							reverse_rotate(&(st->top_b), &(st->down_b), -1);
							write(1, "rrb\n", 4);
						}
					}
				}
				else
				{
					if (next_val > top_val)
					{
						swap(&(st->top_b), &(st->down_b));
						write(1, "sb\n", 3);
					}
				}
			}
			else
			{
				if (down_val < max)
				{
					if (down_val > top_val)
					{
						reverse_rotate(&(st->top_b), &(st->down_b), -1);
						write(1, "rrb\n", 4);
					}
				}
			}
			push_a(st);
			write(1, "pa\n", 3);
		}
		else if (next_val < max)
		{
			if (down_val < max)
			{
				if (next_val > down_val)
				{
					swap(&(st->top_b), &(st->down_b));
					write(1, "sb\n", 3);
				}
				else
				{
					reverse_rotate(&(st->top_b), &(st->down_b), -1);
					write(1, "rrb\n", 4);
				}
			}
			else
			{
				swap(&(st->top_b), &(st->down_b));
				write(1, "sb\n", 3);
			}
			push_a(st);
			write(1, "pa\n", 3);
		}
		else if (down_val < max)
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
			push_a(st);
			write(1, "pa\n", 3);
		}
		else
			return ;
	}
	push_a(st);
	write(1, "pa\n", 3);
	if (st->top_a->p_pos > st->top_a->next->p_pos)
	{
		rotate(&(st->top_a), &(st->down_a), -1);
		write(1, "ra\n", 3);
	}
}

void	sent_neg_a(t_storage *st)
{
	int max;
	int top_val;
	int next_val;
	int down_val;

	if (st->top_b->p_pos < st->down_b->p_pos)
	{
		if (st->top_b->next->p_pos > st->down_b->p_pos)
		{
			swap(&(st->top_b), &(st->down_b));
			write(1, "sb\n", 3);
		}
		else
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
		}
	}
	push_a(st);
	write(1, "pa\n", 3);
	max = st->top_a->p_pos;
	rotate(&(st->top_a), &(st->down_a), -1);
	write(1, "ra\n", 3);
	while (st->down_b)
	{
		top_val = st->top_b->p_pos;
		next_val = st->top_b->next->p_pos;
		down_val = st->down_b->p_pos;
		if (top_val < max)
		{
			if (next_val < max)
			{
				if (down_val < max)
				{
					if (top_val > next_val)
					{
						if (down_val > top_val)
						{
							reverse_rotate(&(st->top_b), &(st->down_b), -1);
							write(1, "rrb\n", 4);
						}
					}
					else
					{
						if (next_val > down_val)
						{
							swap(&(st->top_b), &(st->down_b));
							write(1, "sb\n", 3);
						}
						else
						{
							reverse_rotate(&(st->top_b), &(st->down_b), -1);
							write(1, "rrb\n", 4);
						}
					}
				}
				else
				{
					if (next_val > top_val)
					{
						swap(&(st->top_b), &(st->down_b));
						write(1, "sb\n", 3);
					}
				}
			}
			else
			{
				if (down_val < max)
				{
					if (down_val > top_val)
					{
						reverse_rotate(&(st->top_b), &(st->down_b), -1);
						write(1, "rrb\n", 4);
					}
				}
			}
			push_a(st);
			write(1, "pa\n", 3);
			max = st->top_a->p_pos;
			rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "ra\n", 3);
		}
		else if (next_val < max)
		{
			if (down_val < max)
			{
				if (next_val > down_val)
				{
					swap(&(st->top_b), &(st->down_b));
					write(1, "sb\n", 3);
				}
				else
				{
					reverse_rotate(&(st->top_b), &(st->down_b), -1);
					write(1, "rrb\n", 4);
				}
			}
			else
			{
				swap(&(st->top_b), &(st->down_b));
				write(1, "sb\n", 3);
			}
			push_a(st);
			write(1, "pa\n", 3);
			max = st->top_a->p_pos;
			rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "ra\n", 3);
		}
		else if (down_val < max)
		{
			reverse_rotate(&(st->top_b), &(st->down_b), -1);
			write(1, "rrb\n", 4);
			push_a(st);
			write(1, "pa\n", 3);
			max = st->top_a->p_pos;
			rotate(&(st->top_a), &(st->down_a), -1);
			write(1, "ra\n", 3);
		}
		else
			return ;
	}
	push_a(st);
	write(1, "pa\n", 3);
	if (st->top_a->p_pos < st->down_a->p_pos)
	{
		rotate(&(st->top_a), &(st->down_a), -1);
		write(1, "ra\n", 3);
	}
}

int		merge_sort(t_storage *st)
{
	int iter_id;

	if (st->len_a <= 3)
		sort3(st);
	else
	{
		iter_id = 0;
		while (iter_id != 1)
		{
			iter_id = 0;
			while (st->top_a)
			{
				sent_posit_b(st);
				if (st->top_a)
				{
					sent_neg_b(st);
				}
			}
			while (st->top_b)
			{
				iter_id++;
				sent_posit_a(st);
				if (st->top_b)
				{
					iter_id++;
					sent_neg_a(st);
				}
			}
		}
	}
	ft_free_storage(st);
	return (EXIT_SUCCESS);
}
