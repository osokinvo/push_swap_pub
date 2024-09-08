/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:23:46 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/16 23:39:34 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_listi.h"

t_storage	*ft_create_storage(void)
{
	t_storage *result;

	if (!(result = (t_storage *)malloc(sizeof(t_storage))))
		return (NULL);
	result->down_a = NULL;
	result->down_b = NULL;
	result->len_a = 0;
	result->len_b = 0;
	result->top_a = NULL;
	result->top_b = NULL;
	result->fd = 0;
	result->flags = 1;
	// result->block = 0;
	// result->ta = 0;
	// result->tb = 0;
	// result->tb_block = 0;
	// result->da = 0;
	// result->da_block = 0;
	// result->db = 0;
	// result->db_block = 0;
	return (result);
}

void		ft_free_storage(t_storage *storage)
{
	if (!(storage))
		return ;
	if (storage->top_a)
		ft_free_listi(storage->top_a);
	if (storage->top_b)
		ft_free_listi(storage->top_b);
	if (storage->fd != 0)
		close(storage->fd);
	free(storage);
}

void		ft_free_listi(t_listi *head)
{
	if (head->next)
		ft_free_listi(head->next);
	free(head);
}

t_listi		*ft_create_listi(int n, t_listi *next)
{
	t_listi *new;

	if (!(new = (t_listi *)malloc(sizeof(t_listi))))
	{
		if (next)
			ft_free_listi(next);
		return (NULL);
	}
	new->n = n;
	new->next = next;
	return (new);
}

void		ft_set_flag(t_storage *storage, char c)
{
	if (c == 'c')
		storage->flags = 'c';
	else if (c == 'v' && storage->flags != 'c')
		storage->flags = 'v';
	else if (c == 'g' && storage->flags == 1)
		storage->flags = 'g';
}
