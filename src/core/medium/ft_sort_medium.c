/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:50:20 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/15 21:13:21 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_chunks_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		rotate_pos_top(b, max_pos, 'b');
		ft_pa(a, b);
	}
}

void	ft_chunks_to_b(t_stack *a, t_stack *b, int pivot, int chunk)
{
	t_node	*tmp;
	int		pos;

	while (b->size < pivot + chunk && a->size > 3)
	{
		pos = 0;
		tmp = a->head;
		while (!(tmp->index >= pivot && tmp->index <= pivot + chunk))
		{
			pos++;
			tmp = tmp->next;
		}
		rotate_pos_top(a, pos, 'a');
		ft_pb(a, b);
		if (b && b->head->index <= pivot + (chunk / 2))
			ft_rb(b);
	}
}

void	ft_sort_medium(t_stack *a, t_stack *b)
{
	int	pivot;
	int	chunk;
	int	total_size;

	total_size = a->size;
	pivot = 0;
	chunk = int_sqrt(a->size) + 1;
	while (a->size > 3)
	{
		ft_chunks_to_b(a, b, pivot, chunk);
		if (pivot + chunk > total_size)
			chunk = total_size - pivot;
		pivot += chunk;
	}
	ft_sort_three(a);
	ft_chunks_to_a(a, b);
}
