/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:59:26 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 16:28:14 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_istr(char *istr)
{
	int	i;

	i = 0;
	while (ft_isspace(istr[i]))
		i++;
	if (istr[i] == '-' || istr[i] == '+')
		i++;
	if (!istr[i] || !istr)
		return (0);
	while (istr[i])
	{
		if (!ft_isdigit(istr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_int_range(long n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}

void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
