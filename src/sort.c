/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:54:03 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 21:59:44 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_sort(t_stack *a);
static void	medium_sort(t_op *info_op_a,
				t_stack *a, t_stack *b);
static void	general_sort(t_op *info_op_a, t_op *info_op_b,
				t_stack *a, t_stack *b);

int	sort(t_stack *a, t_stack *b)
{
	t_op	info_op_a;
	t_op	info_op_b;

	if (check_stack_c(a) == -1
		&& a -> stack[a -> top] == get_min(a))
		;
	else if (a -> size < 4)
		simple_sort(a);
	else if (a -> size <= 10)
		medium_sort(&info_op_a, a, b);
	else
		general_sort(&info_op_a, &info_op_b, a, b);
	align(cost(&info_op_a, find(a, a -> min), a -> top), a, "ra");
	return (1);
}

// Work for very small size stack ie: size < 4
static void	simple_sort(t_stack *a)
{
	while (check_stack_c(a) != -1)
	{
		if (a -> stack[a -> top - 1] < a -> stack[a -> top])
			swap(a, "sa");
		if (check_stack_c(a) != -1)
		{
			if (check_stack_c(a) == 2)
				rotate_down(a, "ra");
			else
				rotate_up(a, "ra");
		}
	}
}

static void	medium_sort(t_op *info_op_a,
			t_stack *a, t_stack *b)
{
	while (a -> top > 2)
		push(a, b, "pb");
	simple_sort(a);
	simple_insert(info_op_a, a, b);
}

static void	general_sort(t_op *info_op_a, t_op *info_op_b,
			t_stack *a, t_stack *b)
{
	make_partition(a, b);
	while (b -> top > -1)
		general_insert(info_op_a, info_op_b, a, b);
}
