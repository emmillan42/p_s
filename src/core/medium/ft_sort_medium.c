/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:50:20 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/17 13:40:50 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunktoa(t_stack *a, t_stack *b)
{
	stack_index_to_top(b, 50, 'b');
	ft_pa(a, b);
	stack_index_to_top(b, 49, 'b');
	ft_pa(a, b);
}

void	ft_chunktob(t_stack *a, t_stack *b, int pivot, int chunk)
{
	int	next;

	if (a->head->index < pivot + chunk)
	{
		ft_pb(a, b);
		if (b->head->value <= (pivot + (chunk / 2)))
		{
			next = next_chunk_pos(a, pivot, chunk);
			if (next <= (a->size / 2))
				ft_rr(a, b);
			else
				ft_rb(b);
		}
	}
	else
	{
		next = next_chunk_pos(a, pivot, chunk);
		rotate_pos_top(a, next_chunk_pos(a, pivot, chunk), 'a');
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b)
{
	int		pivot;
	int		chunk;
	int		total_size;

	pivot = 0;
	total_size = a->size;
	chunk = int_sqrt(total_size) + 1;
	while (a->size > 0)
	{
		while (stack_has_range(a, pivot, pivot + chunk))
			ft_chunktob(a, b, pivot, pivot + chunk);
		if (pivot + chunk > total_size)
			chunk = total_size - pivot;
		pivot += chunk;
	}
	ft_chunktoa(a, b);
}
