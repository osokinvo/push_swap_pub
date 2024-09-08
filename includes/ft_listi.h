/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listi.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: val <val@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:21:55 by ghusk             #+#    #+#             */
/*   Updated: 2020/07/07 06:52:07 by val              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTI_H
# define FT_LISTI_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_listi
{
	struct s_listi	*next;
	int				n;
	int				pos;
	int				p_pos;
	// int				id_block;
}				t_listi;

typedef	struct	s_storage
{
	t_listi		*top_a;
	t_listi		*top_b;
	t_listi		*down_a;
	t_listi		*down_b;
	int			fd;
	int			flags;
	int			len_a;
	int			len_b;
	// int			block;
	// int			ta;
	// int			tb;
	// int			tb_block;
	// int			da;
	// int			da_block;
	// int			db;
	// int			db_block;
}				t_storage;

/*
**	ft_listi
*/

t_listi			*ft_create_listi(int n, t_listi *next);
void			ft_free_listi(t_listi *head);
t_storage		*ft_create_storage(void);
void			ft_free_storage(t_storage *storage);

#endif
