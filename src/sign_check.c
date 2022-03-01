/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:11:43 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/28 19:48:28 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign(char **num_str, int num, int *len)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (*num_str)
	{
		if (**num_str == '-')
			sign = -1;
		if (**num_str >= '0' && **num_str <= '9')
			break ;
		*len -= 1;
		*num_str += 1;
	}
	if ((sign == 1 && num < 0)
		|| (sign == -1 && num >= 0))
		return (1);
	return (0);
}
