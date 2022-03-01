/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:26:51 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/19 00:03:14 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cost to get the element from bottom to up perspective
int	cost_up(t_stack *a, int ceiling)
{
	int	i;

	i = 0;
	while (i <= a -> top)
	{
		if (a -> stack[i] < ceiling
			&& a -> min != a -> stack[i]
			&& a -> max != a -> stack[i])
			return (i);
		i += 1;
	}
	return (-1);
}

// Cost to get the element from up to bottom perspective
int	cost_down(t_stack *a, int ceiling)
{
	int	i;

	i = a -> top;
	while (i >= 0)
	{
		if (a -> stack[i] < ceiling
			&& a -> min != a -> stack[i]
			&& a -> max != a -> stack[i])
			return (i);
		i -= 1;
	}
	return (-1);
}

// Operation calculation, that returns the structure t_op passed to him
// after giving the necessary data
t_op	*cost(t_op *op_info, int down, int top)
{
	int	up;

	up = top - down;
	down += 1;
	if (down < up)
	{
		op_info -> op = DOWN;
		op_info -> count = down;
	}
	else
	{
		op_info -> op = UP;
		op_info -> count = up;
	}
	return (op_info);
}

// Operation cost calculation
int	op_cost(int down, int top)
{
	int	up;

	up = top - down;
	down += 1;
	if (down < up)
		return (down);
	else
		return (up);
}
