/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:15:28 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/17 00:05:33 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_listi.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	funcsh
*/

void	swap(t_listi **top, t_listi **down);
void	push_a(t_storage *store);
void	push_b(t_storage *store);
void	rotate(t_listi **top, t_listi **down, int sort);
void	reverse_rotate(t_listi **top, t_listi **down, int sort);

/*
**	error
*/

int		ft_error_check(t_storage *storage);

/*
**	ft_checker2
*/

int		ft_stack_is_sort(t_storage *store, int checker);
int		ft_read_arg(int *argc, char **argv, int checker, t_storage *storage);

/*
**	visual
*/

void	ft_set_flag(t_storage *storage, char c);
int		flags(t_storage *storage, char *s);

/*
**	smart_sort
*/

int		smart_sort(t_storage *st);

/*
**	insert_sort
*/

int		insert_sort(t_storage *st);

/*
**	merge_sort
*/

int		merge_sort(t_storage *st);

/*
**	quick_sort
*/

int		quick_sort(t_storage *st);
void	to_b(t_storage *st, int k, int sort);
void	to_a(t_storage *st, int k);

/*
**	finder
*/

void	main_func(t_storage *storage);

/*
**	blocks
*/

void	blocks(t_storage *st, int mid, int len);

/*
**	grafics
*/

int		ft_begin_grafics(t_storage *st, char *s);

#endif
