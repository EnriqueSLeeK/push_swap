/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:58 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/20 11:57:05 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_stack_c(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack -> top)
	{
		if (stack -> stack[i] < stack -> stack[i + 1])
			return (1);
		i += 1;
	}
	return (-1);
}
