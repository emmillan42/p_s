/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:27:21 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/08 15:32:07 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc < 2)
		return (0);

	stack = ft_parse_pushswap(&stack, argv);
	if (!read_input(0))
		return (ft_free_stack(stack), 1);
	return (0);
}