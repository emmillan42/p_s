/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:03:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 10:19:05 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_stacklast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	t_stack	*tmp;

	if (!a || !(*a) || !b || !(*b))
		return ;
	tmp = (*b);
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (print == 1)
		write(1, "pb\n", 3);
}



void	ft_sb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	*b = tmp;
	tmp->next = (*b)->next;
	(*b)->next = tmp->next;
	*b = (*b)->next;
	if (print == 1)
		write(1, "pb\n", 3);	
}
