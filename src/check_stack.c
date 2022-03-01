/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/19 00:04:46 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Used to wrap around the index to emulate a
// cyclic motion
int	index_adjust(int i, int top)
{
	if (i > -1 && i <= top)
		return (i);
	else if (i < 0)
		return (top);
	else
		return (0);
}

// Check if the stack it's ok
int	check_stack_c(t_stack *stack)
{
	int	return_index;
	int	counter;
	int	flag;
	int	i;

	flag = 0;
	counter = 0;
	i = find(stack, get_max(stack));
	while (counter < stack -> top)
	{
		return_index = index_adjust(i + counter, stack -> top);
		if (stack -> stack[index_adjust(return_index + 1, stack -> top)]
			> stack -> stack[return_index])
		{
			flag = 1;
			break ;
		}
		counter += 1;
	}
	if (!flag)
		return (-1);
	else
		return (return_index);
}
