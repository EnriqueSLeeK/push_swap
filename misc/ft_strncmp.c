/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:20:16 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 23:01:02 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_func.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i += 1;
	}
	if (i == n && i != 0)
		i -= 1;
	return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
}
