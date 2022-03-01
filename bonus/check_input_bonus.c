/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:11:22 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/28 01:18:41 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_num_format(char *num);
static void	free_str(char **matrix);
static int	check_str(char *str);

static void	free_str(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i += 1;
	}
	free(matrix);
}

// flag 1 - Rejection
// flag 0 - All good and well
static int	check_num_format(char *num)
{
	int	i;
	int	sign;
	int	flag;

	i = 0;
	flag = 0;
	sign = 0;
	while (num[i])
	{
		if (sign > 1)
			flag = 1;
		if (num[i] == '-' || num[i] == '+')
			sign += 1;
		else if (!(ft_isdigit(num[i])))
			flag = 1;
		if (flag)
			break ;
		i += 1;
	}
	if (sign && i == 1)
		flag = 1;
	return (flag);
}

static int	check_segment(char **segment)
{
	int	i;

	i = 0;
	while (segment[i])
	{
		i += 1;
	}
	return (i > 1);
}

static int	check_str(char *str)
{
	char	**str_split;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	str_split = ft_split(str, ' ');
	if (str_split == 0)
		error_exit("Malloc failed", 2);
	while (str_split[i])
	{
		flag = check_segment(str_split);
		if (flag == 0)
			flag = check_num_format(str_split[i]);
		if (flag)
			break ;
		i += 1;
	}
	free_str(str_split);
	return (flag);
}

void	check_input(char **arg)
{
	while (*arg)
	{
		if (check_str(*arg) || **arg == 0)
			error_exit("Error", 2);
		arg += 1;
	}
}
