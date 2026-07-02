/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:28:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 12:54:23 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function iterates over the command line arguments and
activate the flags that are found
errors like more than one flag or invalid flags are already checked
returns error if an invalid input is found, ignore numbers
*/
int	ft_parse_flags(t_stack *a, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (ft_isflag_ps(split[i]))
		{
			if (!ft_setflag_ps(a, split[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_setflag_ps(t_stack *a, char *str)
{
	if (!a || !str)
		return (0);
	if (ft_strcmp("--adaptive", str) == 0)
		a->strategy_arg = str;
	else if (ft_strcmp("--simple", str) == 0)
		a->strategy_arg = str;
	else if (ft_strcmp("--medium", str) == 0)
		a->strategy_arg = str;
	else if (ft_strcmp("--complex", str) == 0)
		a->strategy_arg = str;
	else if (ft_strcmp("--bench", str) == 0)
	{
		a->bench = ft_bench_new();
		if (!a->bench)
			return (0);
	}
	return (1);
}
