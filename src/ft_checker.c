/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:00:20 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/17 00:27:25 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	norm_26(char *s, t_storage *store)
{
	if (!ft_strcmp(s, "rr"))
	{
		rotate(&(store->top_a), &(store->down_a), 1);
		rotate(&(store->top_b), &(store->down_b), -1);
	}
	else if (!ft_strcmp(s, "rra"))
		reverse_rotate(&(store->top_a), &(store->down_a), 1);
	else if (!ft_strcmp(s, "rrb"))
		reverse_rotate(&(store->top_b), &(store->down_b), -1);
	else if (!ft_strcmp(s, "rrr"))
	{
		reverse_rotate(&(store->top_a), &(store->down_a), 1);
		reverse_rotate(&(store->top_b), &(store->down_b), -1);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_match_input_func(char *s, t_storage *store)
{
	if (!ft_strcmp(s, "sa"))
		swap(&(store->top_a), &(store->down_a));
	else if (!ft_strcmp(s, "sb"))
		swap(&(store->top_b), &(store->down_b));
	else if (!ft_strcmp(s, "ss"))
	{
		swap(&(store->top_a), &(store->down_a));
		swap(&(store->top_b), &(store->down_b));
	}
	else if (!ft_strcmp(s, "pa"))
		push_a(store);
	else if (!ft_strcmp(s, "pb"))
		push_b(store);
	else if (!ft_strcmp(s, "ra"))
		rotate(&(store->top_a), &(store->down_a), 1);
	else if (!ft_strcmp(s, "rb"))
		rotate(&(store->top_b), &(store->down_b), -1);
	else
		return (norm_26(s, store));
	return (EXIT_SUCCESS);
}

static int	ft_input_check(t_storage *storage)
{
	char		*s;
	int			ret;

	if (flags(storage, NULL))
		return (ft_error_check(storage));
	while ((ret = get_next_line1(storage->fd, &s)) > 0)
	{
		if (ft_match_input_func(s, storage))
		{
			free(s);
			flags(storage, "Error");
			return (ft_error_check(storage));
		}
		if (flags(storage, s))
		{
			free(s);
			return (ft_error_check(storage));
		}
		free(s);
	}
	if (storage->flags == 'g' && ft_begin_grafics(storage, ""))
		return (ft_error_check(storage));
	if (ret < 0)
		return (ft_error_check(storage));
	return (ft_stack_is_sort(storage, 1));
}

static int	ft_check_list(t_storage *storage)
{
	t_listi	*list1;
	t_listi	*list2;

	list1 = storage->top_a;
	if (!(storage->top_a))
		return (ft_error_check(storage));
	while (list1)
	{
		list2 = list1->next;
		while (list2)
		{
			if (list2->n == list1->n)
				return (ft_error_check(storage));
			list2 = list2->next;
		}
		list1 = list1->next;
	}
	main_func(storage);
	return (ft_input_check(storage));
}

int			main(int argc, char **argv)
{
	t_storage	*storage;

	if (argc > 1)
	{
		if (!(storage = ft_create_storage()))
		{
			return (ft_error_check(NULL));
		}
		while (--argc > 0)
		{
			if (ft_read_arg(&argc, argv, 1, storage))
			{
				return (EXIT_FAILURE);
			}
		}
		return (ft_check_list(storage));
	}
	return (EXIT_FAILURE);
}
