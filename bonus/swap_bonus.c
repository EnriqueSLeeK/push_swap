/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:59:03 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 18:24:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Swap elements at the top of the array
int	swap(t_stack *stack)
{
	int	tmp;

	if (stack -> top > 0)
	{
		tmp = stack -> stack[stack -> top];
		stack -> stack[stack -> top] = stack -> stack[stack -> top - 1];
		stack -> stack[stack -> top - 1] = tmp;
	}
	return (1);
}

int	super_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return (1);
}
