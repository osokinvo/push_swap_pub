/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghusk <ghusk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:57:00 by ghusk             #+#    #+#             */
/*   Updated: 2020/03/10 19:36:16 by ghusk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_check_list(t_storage *storage)
{
	t_listi	*list1;
	t_listi	*list2;

	list1 = storage->top_a;
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
	return (quick_sort(storage));
}

int			main(int argc, char **argv)
{
	t_storage	*storage;

	if (argc > 1)
	{
		if (!(storage = ft_create_storage()))
			return (ft_error_check(NULL));
		while (--argc > 0)
		{
			if (ft_read_arg(&argc, argv, 0, storage))
				return (EXIT_FAILURE);
		}
		return (ft_check_list(storage));
	}
	return (EXIT_FAILURE);
}
