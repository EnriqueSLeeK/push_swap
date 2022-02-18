/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:59:35 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 15:00:21 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	super_align(t_op *op_info_a, t_op *op_info_b, t_stack *a, t_stack *b)
{
	if (op_info_a -> op == UP
		&& op_info_a -> op == op_info_b -> op)
	{
		while (op_info_a -> count > 0 && op_info_b -> count > 0)
		{
			super_rotate_up(a, b);
			op_info_a -> count -= 1;
			op_info_b -> count -= 1;
		}
	}
	else if (op_info_a -> op == DOWN
		&& op_info_a -> op == op_info_b -> op)
	{
		while (op_info_a -> count > 0 && op_info_b -> count > 0)
		{
			super_rotate_down(a, b);
			op_info_a -> count -= 1;
			op_info_b -> count -= 1;
		}
	}
}

void	align(t_op *op_info, t_stack *stack, char *op)
{
	if (op_info -> op == UP)
	{
		while (op_info -> count > 0)
		{
			rotate_up(stack, op);
			op_info -> count -= 1;
		}
	}
	else if (op_info -> op == DOWN)
	{
		while (op_info -> count > 0)
		{
			rotate_down(stack, op);
			op_info -> count -= 1;
		}
	}
}
