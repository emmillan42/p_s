/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/07 14:35:38 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return (1);
	tmp = stack->head;
	while (tmp && tmp->next)
	{
		printf("Stack index is %d", tmp->index);
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_find_index(t_stack *stack, t_node *node)
{
	t_node	*tmp;
	int		pos;

	if (!stack || stack->size == 0)
		return (-1);
	tmp = stack->head;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == node->index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

/*
 * Find the smallest value node
*/
t_node	*find_smallest(t_stack *stack)
{
	t_node	*tmp;
	t_node	*smallest;
	int		min;

	if (NULL == stack)
		return (NULL);
	min = INT_MAX;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			smallest = tmp;
		}
		tmp = tmp->next;
	}
	return (smallest);
}

