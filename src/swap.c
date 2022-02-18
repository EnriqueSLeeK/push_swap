/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:59:03 by ensebast          #+#    #+#             */
/*   Updated: 2021/12/14 00:39:20 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap elements at the top of the array
int	swap(t_stack *stack, char *op)
{
	int	tmp;

	if (stack -> top > 0)
	{
		tmp = stack -> stack[stack -> top];
		stack -> stack[stack -> top] = stack -> stack[stack -> top - 1];
		stack -> stack[stack -> top - 1] = tmp;
	}
	ft_putendl_fd(op, 1);
	return (1);
}

int	super_swap(t_stack *a, t_stack *b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_putendl_fd("ss", 1);
	return (1);
}
