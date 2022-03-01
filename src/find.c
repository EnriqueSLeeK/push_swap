/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:27:02 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/19 00:02:25 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get the biggest elem
int	get_max(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack -> stack[i];
	while (i < stack -> top)
	{
		i += 1;
		if (stack -> stack[i] > tmp)
			tmp = stack -> stack[i];
	}
	return (tmp);
}

// Get the smallest elem
int	get_min(t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack -> stack[i];
	while (i < stack -> top)
	{
		i += 1;
		if (stack -> stack[i] < tmp)
			tmp = stack -> stack[i];
	}
	return (tmp);
}

// Find the nearest number
int	find_nearest(t_stack *stack, int ref)
{
	int	i;

	i = find(stack, get_min(stack));
	while (1)
	{
		if (ref < stack -> stack[i])
			return (i);
		i = index_adjust(i - 1, stack -> top);
	}
}

// This function is used to find the max or min element
int	find(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack -> top >= i)
	{
		if (stack -> stack[i] == target)
			return (i);
		i += 1;
	}
	return (-1);
}

// Find element less than a certain ceiling
int	find_less_than(t_stack *a, int ceiling)
{
	int	index_u;
	int	index_d;

	index_u = cost_up(a, ceiling);
	index_d = cost_down(a, ceiling);
	if (index_u + 1 < (a -> top) - index_d)
		return (index_u);
	else
		return (index_d);
}
