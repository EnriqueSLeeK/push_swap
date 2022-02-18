/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:52:46 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 18:16:22 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
 * will push an element from stack_one to stack_second
*/
int	push(t_stack *stack_one, t_stack *stack_second)
{
	if (stack_one -> top >= 0)
	{
		stack_second -> top += 1;
		stack_second -> stack[stack_second -> top] = stack_one -> stack
		[stack_one -> top];
		stack_one -> top -= 1;
		return (1);
	}
	return (0);
}
