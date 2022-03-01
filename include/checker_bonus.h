/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:13:21 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/28 01:14:58 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "misc_func.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	top;
}	t_stack;

void	check_input(char **arg);
int		check_stack_c(t_stack *stack);

void	init_stack(t_stack *a, t_stack *b, char **arg, int argc);

int		push(t_stack *stack_one, t_stack *stack_two);

int		rotate_down(t_stack *stack);
int		super_rotate_down(t_stack *stack_one, t_stack *stack_two);

int		rotate_up(t_stack *stack);
int		super_rotate_up(t_stack *stack_one, t_stack *stack_two);

int		swap(t_stack *stack);
int		super_swap(t_stack *stack_one, t_stack *stack_two);

int		check_sign(char **num_str, int num, int *len);

void	error_exit(char *msg, int code);

#endif
