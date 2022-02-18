/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:34:26 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 21:59:03 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_arr(t_stack *a)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (a -> size));
	while (a -> top >= i)
	{
		arr[i] = a -> stack[i];
		i += 1;
	}
	return (arr);
}

static int	*bubble_sort(t_stack *a)
{
	int	i;
	int	k;
	int	tmp;
	int	*arr;

	i = 0;
	arr = copy_arr(a);
	while (i <= a -> top)
	{
		k = 0;
		while (k < a -> top)
		{
			if (arr[k] > arr[k + 1])
			{
				tmp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = tmp;
			}
			k += 1;
		}
		i += 1;
	}
	return (arr);
}

static int	check_move(t_stack *a, int ceiling)
{
	int	i;
	int	count;

	i = a -> top;
	count = 0;
	while (count <= a -> top)
	{
		if (a -> stack[a -> top] < a -> stack[i]
			&& a -> stack[i] <= ceiling)
			return (-1);
		if (a -> stack[i] == a -> min)
			return (0);
		count += 1;
		i = index_adjust(i + 1, a -> top);
	}
	return (1);
}

static void	push_rotate(t_stack *a, t_stack *b, t_aux *aux)
{
	while (a -> top > aux -> top)
	{
		if (a -> stack[a -> top] < aux -> ceiling
			&& a -> stack[a -> top] != a -> min
			&& check_move(a, aux -> ceiling))
			push(a, b, "pb");
		else
		{
			if (a -> stack[a -> top] != a -> max
				&& a -> stack[a -> top] != a -> min)
				aux -> top += 1;
			rotate_up(a, "ra");
		}
	}
}

void	make_partition(t_stack *a, t_stack *b)
{
	t_aux	aux;
	int		*arr;

	arr = bubble_sort(a);
	aux.top = 1;
	aux.ceiling = arr[(a -> size / 2) - 1];
	push_rotate(a, b, &aux);
	aux.top = 1;
	aux.ceiling = arr[a -> size - 1];
	push_rotate(a, b, &aux);
	free(arr);
}
