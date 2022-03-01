/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:49:32 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/18 23:54:54 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Simple insertion for the simple strategy
void	simple_insert(t_op *info_op_a, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	max = get_max(a);
	min = get_min(a);
	while (b -> top > -1)
	{
		if (b -> stack[b -> top] < min)
		{
			align(cost(info_op_a, find(a, min), a -> top), a, "ra");
			min = b -> stack[b -> top];
		}
		else if (b -> stack[b -> top] > max)
		{
			align(cost(info_op_a, find(a, min), a -> top), a, "ra");
			max = b -> stack[b -> top];
		}
		else
			align(cost(info_op_a, find_nearest(a, b -> stack[b -> top]),
					a -> top), a, "ra");
		push(b, a, "pa");
	}
}

static void	get_index(t_index *indexes, int i, int k)
{
	indexes -> index_a = k;
	indexes -> index_b = i;
}

static int	index_greater(int ref, t_stack *a)
{
	int	i;
	int	count;

	i = find(a, a -> min);
	count = 0;
	while (count <= a -> top)
	{
		if (ref < a -> stack[i])
			break ;
		i = index_adjust(i - 1, a -> top);
		count += 1;
	}
	return (i);
}

static void	choose_best(t_stack *a, t_stack *b, t_index *indexes)
{
	int	i;
	int	k;
	int	tmp_cost;
	int	total_cost;

	i = 0;
	total_cost = a -> size * 2;
	while (i <= b -> top)
	{
		k = index_greater(b -> stack[i], a);
		tmp_cost = op_cost(i, b -> top) + op_cost(k, a -> top);
		if (total_cost > tmp_cost)
		{
			total_cost = tmp_cost;
			get_index(indexes, i, k);
		}
		i += 1;
	}
}

void	general_insert(t_op *info_op_a, t_op *info_op_b, t_stack *a, t_stack *b)
{
	t_index	indexes;

	indexes.index_a = 0;
	indexes.index_b = 0;
	choose_best(a, b, &indexes);
	cost(info_op_a, indexes.index_a, a -> top);
	cost(info_op_b, indexes.index_b, b -> top);
	if (info_op_a -> op == info_op_b -> op)
		super_align(info_op_a, info_op_b, a, b);
	align(info_op_a, a, "ra");
	align(info_op_b, b, "rb");
	push(b, a, "pa");
}
