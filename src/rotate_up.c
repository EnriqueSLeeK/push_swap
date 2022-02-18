/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:02:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 13:50:04 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_up(t_stack *stack, char *op)
{
	int	tmp;
	int	i;

	if (stack -> top > 0)
	{
		i = stack -> top;
		tmp = stack -> stack[stack -> top];
		while (i > 0)
		{
			stack -> stack[i] = stack -> stack[i - 1];
			i -= 1;
		}
		stack -> stack[0] = tmp;
	}
	if (op != NULL)
	{
		ft_putendl_fd(op, 1);
		return (1);
	}
	return (0);
}

int	super_rotate_up(t_stack *a, t_stack *b)
{
	rotate_up(a, NULL);
	rotate_up(b, NULL);
	ft_putendl_fd("rr", 1);
	return (1);
}
