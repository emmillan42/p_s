/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:40:49 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 17:46:14 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
HUGE RESPONSIBILITY ON THIS FUNCTION
Validate that we have received a valid input from the user.
Scenarios to contemplate:
./push_swap.out " 35 46 7   " 9 8 7 --simple
./push_swap.out 34 45  "" 9 8 7 " " "   " --> parse integers only until 45.
./push_swap.out 34 45  " 99 hola 3" 9 --> parse integers only until 99.
./push_swap.out "" "  " " 35 46 7  --complex " 9 8 7 

Example invalid inputs:

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo

For each argv, split it in case it is a quoted string, iterate
over the split to check if an invalid input is found.

by: durisosa
*/
int	ft_valid_args(int argc, char **argv)
{
	char	**split;
	int		strategy_count;
	int		i;
	int		j;

	i = 0;
	strategy_count = 0;
	while (i < argc && strategy_count < 2)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[i])
			return (0);
		j = 0;
		while (split[j])
		{
			if (!ft_valid_args_split(split[j], &strategy_count))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_valid_args_split(char *str, int *strategy_count)
{
	if (!ft_isflag_pushswap(str) && !ft_valid_istr(str))
		return (0);
	if (ft_isstrategy(str))
		*strategy_count++;
	if (strategy_count > 1)
		return (0);
	return (1);
}

/*
creates an array of integers using an array of chars
ignores flags. Stops when find somethind that is not a number.

any invalid input was previously checked, so this function
assumes no invalid flags are present.
it fails if finds an invalid integer.
For example "--a" "+ maria", etc.

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo
*/
int	ft_parse_integers(t_stack **a, int argc, char **argv)
{
	char	**split;
	int		stop;
	int		i;
	int		j;

	i = 0;
	stop = 0;
	while (i < argc && !stop)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ft_free_split(split), 0);
		j = 0;
		while (split[j] && !stop)
		{
			if (!ft_parse_integers_split(a, split[j], &stop))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_integers_split(t_stack **a, char *str, int *stop)
{
	long	value;

	if (!ft_valid_istr(str) && !ft_isflag_pushswap(str))
		return (0);
	if (!ft_valid_istr(str))
		*stop = 1;
	value = ft_atol(str);
	if (!ft_valid_value_stack(value))
		return (0);
	ft_stackadd_back(a, ft_node_new(value, 0));
	return (1);
}


/*
this function iterates over the command line arguments and
activate the flags that are found
errors like more than one flag or invalid flags are already checked
returns error if an invalid input is found, ignore numbers
*/
int	ft_parse_flags(t_stack **a, int argc, char **argv)
{
	char	**split;
	int		stop;
	int		i;
	int		j;

	i = 0;
	stop = 0;
	while (i < argc && !stop)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ft_free_split(split), 0);
		j = 0;
		while (split[j] && !stop)
		{
			if (!ft_parse_flags_split(a, split[j], &stop))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_flags_split(t_stack **a, char *str, int *stop)
{
	long	value;

	if (ft_isflag_pushswap(str))
		ft_stack_setflag(a, str);
	if ((*a)->strategy != NULL && (*a)->bench != NULL)
		*stop = 1;
	return (1);
}

int	ft_parse_pushswap(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;

	i = -1;
	(*a) = ft_stacknew();
	(*b) = ft_stacknew();
	if (!*a || !*b)
		return (free(*a), free(*b), 0);
	if (ft_parse_flags(a, argv, argc) == 0)
		return (free(*a), free(*b), 0);
	if (ft_parse_integers(a, argv, argc) == 0)
		return (free(*a), free(*b), 0);
	ft_print_stack(*a);
	return (1);
}



int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	if (!ft_valid_args(argc, argv))
		return (1);
	if (!ft_parse_pushswap(&a, &b, argc, argv))
		return (1);
	if (!ft_stacksorted(a))
		ft_sort_strategy(&a, &b);
	if (!!a->bench)
		ft_print_bench(a);
	return (ft_free_stack(&a), ft_free_stack(&b), 0);
}
