/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:36:34 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 17:42:35 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->bench = NULL;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_node *new)
{
	t_node	*node;

	if (!stack || !*stack || !node)
		return ;
	new->prev = ft_stacklast(*stack);
	new->next = NULL;
	node = (*stack)->head;
	if (!node)
	{
		(*stack)->head = new;
		(*stack)->tail = new;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	(*stack)->size++;
}

void	ft_stackadd_front(t_stack **stack, t_node *new)
{
	t_node	*node;

	if (!stack || !*stack || !node)
		return ;
	new->prev = NULL;
	node = (*stack)->head;
	new->next = node;
	if (!node)
		(*stack)->tail = new;
	(*stack)->head = new;
	(*stack)->size++;
}
