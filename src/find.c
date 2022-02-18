/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:27:02 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 21:56:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_nearest(t_stack *stack, int ref)
{
	int	i;
	int	dist;
	int	target_index;

	i = 0;
	target_index = 0;
	dist = get_min(stack);
	if (dist < 0)
		dist *= -1;
	if (dist < get_max(stack))
		dist = get_max(stack);
	while (stack -> top >= i)
	{
		if (ref - stack -> stack[i] > 0
			&& dist > ref - stack -> stack[i])
		{
			dist = ref - stack -> stack[i];
			target_index = i;
		}
		i += 1;
	}
	target_index -= 1;
	if (target_index < 0)
		target_index = stack -> top;
	return (target_index);
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
