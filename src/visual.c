/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:01:39 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/07 08:19:44 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static void	write_head(char *str)
{
	if (!(str))
		write(1, "\tBegin cheker\n", 14);
	else
	{
		write(1, "\n\tOperation is ", 15);
		write(1, str, ft_strlen(str));
	}
	write(1, "\n--------------|--------------\n", 31);
	write(1, "|      a      |      b      |\n", 30);
	write(1, "|-------------|-------------|\n", 30);
}

static void	ft_print_num(t_listi *list, int color)
{
	size_t	k;
	char	*c;

	if (color)
	{
		if (list->p_pos == list->pos)
			write(1, "\033[32m", 5);
		else
			write(1, "\033[31m", 5);
	}
	c = ft_itoa(list->n);
	k = ft_strlen(c);
	write(1, c, k);
	free(c);
	if (color)
		write(1, "\033[0m", 4);
	k = 12 - k;
	while (k--)
		write(1, " ", 1);
}

void		ft_begin_visual(t_listi *stack_a, t_listi *stack_b, char *str,
			int color)
{
	write_head(str);
	while (stack_a || stack_b)
	{
		write(1, "| ", 2);
		if (stack_a)
		{
			ft_print_num(stack_a, color);
			stack_a = stack_a->next;
		}
		else
			write(1, "            ", 12);
		write(1, "| ", 2);
		if (stack_b)
		{
			ft_print_num(stack_b, color);
			stack_b = stack_b->next;
		}
		else
			write(1, "            ", 12);
		write(1, "|\n--------------|--------------\n", 32);
	}
}

int			flags(t_storage *storage, char *s)
{
	if (storage->flags == 'c')
		ft_begin_visual(storage->top_a, storage->top_b, s, 1);
	else if (storage->flags == 'v')
		ft_begin_visual(storage->top_a, storage->top_b, s, 0);
	else if (storage->flags == 'g')
	{
		if (ft_begin_grafics(storage, s))
			return (1);
	}
	return (0);
}
