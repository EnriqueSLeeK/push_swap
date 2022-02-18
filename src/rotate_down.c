/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:00:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 13:40:17 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_down(t_stack *stack, char *op)
{
	int	i;
	int	tmp;

	if (stack -> top > 0)
	{
		i = 0;
		tmp = stack -> stack[0];
		while (i < stack -> top)
		{
			stack -> stack[i] = stack -> stack[i + 1];
			i += 1;
		}
		stack -> stack[stack -> top] = tmp;
	}
	if (op != NULL)
	{
		ft_putchar_fd('r', 1);
		ft_putendl_fd(op, 1);
		return (1);
	}
	return (0);
}

int	super_rotate_down(t_stack *a, t_stack *b)
{
	rotate_down(a, NULL);
	rotate_down(b, NULL);
	ft_putendl_fd("rrr", 1);
	return (1);
}
