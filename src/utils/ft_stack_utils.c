/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:48:38 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 12:40:55 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (stack->bench)
		free(stack->bench);
	stack->bench = NULL;
	free(stack);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (NULL);
	node = stack->head;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_node	*node;

	if (stack == NULL)
		return (0);
	i = 0;
	node = stack->head;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_stackset_index(t_stack **stack)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	if (!stack)
		return ;
	i = 0;
	node = (*stack)->head;
	while (node != NULL)
	{
		tmp = node;
		i = 0;
		while (tmp != NULL)
		{
			if (tmp->value < node->value)
				i++;
			tmp = tmp->next;
		}
		node->index = i;
		node = node->next;
	}
}
