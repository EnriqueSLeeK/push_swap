/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:31:50 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/28 01:00:20 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "misc_func.h"

# define DOWN 0
# define UP 1

//top = will be the last index
//size = the current stack size
//stack = int pointer will hold the stack
typedef struct s_stack
{
	int	*stack;
	int	min;
	int	max;
	int	size;
	int	top;
}	t_stack;

typedef struct s_index
{
	int	index_a;
	int	index_b;
}	t_index;

typedef struct s_aux
{
	int	top;
	int	ceiling;
}	t_aux;

typedef struct s_op
{
	int	op;
	int	count;
}	t_op;

// input check and initializer of the stack
void	check_input(char **arg);
int		check_stack_c(t_stack *stack);
void	init_stack(t_stack *a, t_stack *b, char **arg, int argc);

// Exit function in case of error
void	error_exit(char *msg, int code);

// Push operation
int		push(t_stack *stack_one, t_stack *stack_second, char *op);

// Swap operation
int		swap(t_stack *stack, char *op);
int		super_swap(t_stack *a, t_stack *b);

// Rotate up
int		rotate_up(t_stack *stack, char *op);
int		super_rotate_up(t_stack *a, t_stack *b);

// Rotate down
int		rotate_down(t_stack *stack, char *op);
int		super_rotate_down(t_stack *a, t_stack *b);

// Sort
int		sort(t_stack *a, t_stack *b);

// Partition
void	make_partition(t_stack *a, t_stack *b);

// Checker
int		cost_up(t_stack *a, int ceiling);
int		cost_down(t_stack *a, int ceiling);
int		op_cost(int down, int top);
t_op	*cost(t_op *op_info, int down, int top);

// Insert
void	simple_insert(t_op *op_info_a,
			t_stack *a, t_stack *b);
void	general_insert(t_op *op_info_a, t_op *op_info_b,
			t_stack *a, t_stack *b);

// Search
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		find(t_stack *stack, int target);
int		find_nearest(t_stack *stack, int ref);
int		find_less_than(t_stack *a, int ceiling);

// Misc
int		index_adjust(int i, int top);
int		check_sign(char **num_str, int num, int *len);
void	super_align(t_op *op_info_a, t_op *op_info_b, t_stack *a, t_stack *b);
void	align(t_op *op_info, t_stack *stack, char *op);
#endif
