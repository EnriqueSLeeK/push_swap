/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:15 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 23:01:08 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "misc_func.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}