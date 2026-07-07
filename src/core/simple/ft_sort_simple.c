/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:39 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/07 14:18:17 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This algorithm is known as the turk sort, which is goiing to:
1. Push elements from A to B until there are only 3 in A.
2. Stack B is going to be pushed with previous calculations,
with the goal of making stack B to be sorted from greatest to 
smallest. 

Before each push, we calculate:
	a. target of each node 'to_push'.
	b. cost of each node.
	c. return cheapest node.
	d. rotate until cheapest node is on top of A.
	e. rotate until cheapest->target is on top of B.
	f. push A to B.
	g. repeat until there are only 3 elements in A.
	
3. Sort A with sort_three();

4. Push all elements back to A.
5. If minimum of A is not on top, move it to the top.
*/
void	ft_sort_simple(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	ft_pb(a, b);
	ft_pb(a, b);
	while (a->size > 3)
	{
		update_positions(a);
		update_positions(b);
		update_targets_a(a, b);
		update_costs(a, b);
		cheapest = find_cheapest(a);
		while (a->head != cheapest && b->head != cheapest->target)
			ft_rrr(a, b);
		while (a->head != cheapest)
			ft_ra(a);
		while (b->head != cheapest->target)
			ft_rb(b);
		ft_pb(a, b);
	}
	ft_sort_three(a);
	ft_push_b_to_a(a, b);
}

/*
How to find cheapest movement?
total movements = rotations of A to bring 'to_push' to top of A
+ rotations of B to bring 'to_push->target' to top of B.
*/

/*
Push back to A.
Numbers in B are sorted from greatest to smalles (descending)


*/
void	ft_push_b_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		ft_pa(a, b);
	update_positions(a);
	rotate_to_top(a, find_smallest(a), 'a');
}






