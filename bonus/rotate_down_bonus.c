/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:00:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 18:23:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	rotate_down(t_stack *stack)
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
	return (1);
}

int	super_rotate_down(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	return (1);
}
