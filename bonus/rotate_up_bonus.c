/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:02:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 18:24:04 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	rotate_up(t_stack *stack)
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
	return (1);
}

int	super_rotate_up(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	return (1);
}
