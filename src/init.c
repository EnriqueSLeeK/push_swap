/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:38:22 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 22:02:47 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Note: This file contains functions to create the stack,
// duplicate elem checking and integer parsing

static void	init_size_top(t_stack *a, t_stack *b, int argc);
static int	check_overflow(t_stack *a, char **arg);
static void	populate(t_stack *stack, char **arg);
static int	check_dup(t_stack *a);

static void	populate(t_stack *stack, char **arg)
{
	int		i;

	i = 0;
	while (i <= stack -> top)
	{
		stack -> stack[stack -> top - i] = ft_atoi(arg[i]);
		i++;
	}
}

static void	init_size_top(t_stack *a, t_stack *b, int argc)
{
	a -> top = argc - 2;
	a -> size = argc - 1;
	b -> size = argc - 1;
	b -> top = -1;
}

static int	check_dup(t_stack *a)
{
	int	i;
	int	k;

	i = 0;
	while (i < a -> size)
	{
		k = 0;
		while (k < a -> size)
		{
			if (i != k && a -> stack[i] == a -> stack[k])
				return (1);
			k += 1;
		}
		i += 1;
	}
	return (0);
}

static int	check_overflow(t_stack *a, char **arg)
{
	int	i;
	int	k;
	int	tmp;
	int	len;

	i = 0;
	while (arg[i])
	{
		k = 0;
		len = ft_strlen(arg[i]);
		tmp = a -> stack[a -> top - i];
		while ((len - 1 - k) >= 0)
		{
			if (arg[i][len - 1 - k] == '-' && tmp <= 0)
				;
			else if (tmp >= 0 && tmp % 10 != arg[i][len - 1 - k] - '0')
				return (1);
			else if (tmp <= 0 && -1 * (tmp % 10) != arg[i][len - 1 - k] - '0')
				return (1);
			tmp /= 10;
			k += 1;
		}
		i += 1;
	}
	return (0);
}

void	init_stack(t_stack *a, t_stack *b, char **arg, int argc)
{
	init_size_top(a, b, argc);
	a -> stack = malloc(a -> size * sizeof(int));
	if (a -> stack == 0)
	{
		error_exit("Error", 2);
	}
	populate(a, arg);
	if (check_dup(a) || check_overflow(a, arg))
	{
		free(a -> stack);
		error_exit("Error", 3);
	}
	if (a -> top > -1)
	{
		a -> max = get_max(a);
		a -> min = get_min(a);
	}
	b -> stack = malloc(b -> size * sizeof(int));
	if (b -> stack == 0)
	{
		free(a -> stack);
		error_exit("Error", 3);
	}
	b -> min = -1;
	b -> max = -1;
}
