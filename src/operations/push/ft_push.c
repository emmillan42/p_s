/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:18:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 10:29:52 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	if (!b || !*b)
		return ;
	ft_push(b, a);
	pushswap->pa_count++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	if (!a || !*a)
		return ;
	ft_push(a, b);
	pushswap->pb_count++;
	write(1, "pb\n", 3);
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	*dest = (*dest)->next;
	*dest = *src;
}
