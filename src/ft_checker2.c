/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:43:11 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/17 00:02:45 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_str_arg(t_storage *storage, int n, char *s)
{
	t_listi	*list;

	if (!(storage->top_a = ft_create_listi(n, storage->top_a)))
		return (EXIT_FAILURE);
	list = storage->top_a;
	n = ft_atoi1(s + 1, &s, 1);
	while (*s == ' ')
	{
		if (!(list->next = ft_create_listi(n, list->next)))
			return (EXIT_FAILURE);
		n = ft_atoi1(s + 1, &s, 1);
		list = list->next;
	}
	if (*s == '\0')
	{
		if (!(list->next = ft_create_listi(n, list->next)))
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	return_program(t_storage *store, int sort, int checker)
{
	if (checker)
	{
		ft_free_storage(store);
		if (sort)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		return (EXIT_SUCCESS);
	}
	return (sort);
}

int			ft_stack_is_sort(t_storage *store, int checker)
{
	t_listi *list;
	t_listi	*list_next;

	if (store->top_b)
	{
		return (return_program(store, 0, checker));
	}
	list = store->top_a;
	while ((list_next = list->next))
	{
		if (list_next->n < list->n)
		{
			return (return_program(store, 0, checker));
		}
		list = list_next;
	}
	return (return_program(store, 1, checker));
}

static int	ft_option(char **argv, int *k, t_storage *storage)
{
	char	*str;

	str = argv[(*k)];
	if ((*k) > 1 && *(argv[(*k) - 1]) == '-' &&
	ft_is_char('f', argv[(*k) - 1]) && (storage->fd = open(str, O_RDONLY)) >= 0)
	{
		(*k)--;
		str = argv[(*k)];
		while (*(++str) != '\0')
		{
			if (!(*str =='c' || *str =='v' || *str =='g' || *str =='f'))
				return (EXIT_FAILURE);
			ft_set_flag(storage, *str);
		}
		return (EXIT_SUCCESS);
	}
	else if (*str == '-' && str[1] != '\0')
	{
		while (*(++str) != '\0')
		{
			if (!(*str =='c' || *str =='v' || *str =='g'))
				return (EXIT_FAILURE);
			ft_set_flag(storage, *str);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int			ft_read_arg(int *argc, char **argv, int checker, t_storage *storage)
{
	int		n;
	char	*s;

	if (*(argv[*argc]) == '\0')
		return (ft_error_check(storage));
	n = ft_atoi1(argv[*argc], &s, 1);
	if (*s == ' ')
	{
		if (ft_str_arg(storage, n, s))
			return (ft_error_check(storage));
	}
	else if (*s == '\0')
	{
		if (!(storage->top_a = ft_create_listi(n, storage->top_a)))
			return (ft_error_check(storage));
	}
	else if (checker)
	{
		if (ft_option(argv, argc, storage))
			return (ft_error_check(storage));
	}
	else
		return (ft_error_check(storage));
	return (EXIT_SUCCESS);
}
