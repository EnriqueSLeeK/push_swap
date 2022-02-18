/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:55:42 by ensebast          #+#    #+#             */
/*   Updated: 2022/02/17 23:06:47 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_FUNC_H
# define MISC_FUNC_H

# include <stdlib.h>

int		ft_isdigit(int elem);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *s, size_t n);
#endif
