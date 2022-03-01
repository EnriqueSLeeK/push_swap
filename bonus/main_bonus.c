/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:03:04 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/28 15:13:04 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>

static char	*get_op(void)
{
	char	*buff;
	int		i;

	buff = ft_calloc(6, sizeof(char));
	i = read(0, buff, 1);
	while (i != 0 && buff[i - 1] != '\n')
	{
		i += read(0, buff + i, 1);
	}
	if (i == 0)
	{
		free(buff);
		buff = 0;
	}
	return (buff);
}

static void	unkown_action(char *op, t_stack *a, t_stack *b)
{
	free(op);
	free(a -> stack);
	free(b -> stack);
	error_exit("Error", 2);
}

static void	execute(char *op, t_stack *a, t_stack *b, unsigned int len)
{
	if (ft_strncmp("sa", op, len) == 0)
		swap(a);
	else if (ft_strncmp("sb", op, len) == 0)
		swap(b);
	else if (ft_strncmp("ss", op, len) == 0)
		super_swap(a, b);
	else if (ft_strncmp("ra", op, len) == 0)
		rotate_up(a);
	else if (ft_strncmp("rb", op, len) == 0)
		rotate_up(b);
	else if (ft_strncmp("rr", op, len) == 0)
		super_rotate_up(a, b);
	else if (ft_strncmp("rra", op, len) == 0)
		rotate_down(a);
	else if (ft_strncmp("rrb", op, len) == 0)
		rotate_down(b);
	else if (ft_strncmp("rrr", op, len) == 0)
		super_rotate_down(a, b);
	else if (ft_strncmp("pb", op, len) == 0)
		push(a, b);
	else if (ft_strncmp("pa", op, len) == 0)
		push(b, a);
	else
		unkown_action(op, a, b);
}

static int	action(t_stack *a, t_stack *b)
{
	char	*op;

	op = get_op();
	while (op != NULL)
	{
		execute(op, a, b, ft_strlen(op) - 1);
		free(op);
		op = get_op();
	}
	if (check_stack_c(a) == -1 && b -> top == -1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	check_input(&argv[1]);
	init_stack(&a, &b, &argv[1], argc);
	if (argc > 1)
		action(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}
