/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:03:04 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 21:53:55 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	check_input(&argv[1]);
	init_stack(&a, &b, &argv[1], argc);
	if (argc > 2)
		sort(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
