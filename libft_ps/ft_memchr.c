/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 04:49:47 by ybong             #+#    #+#             */
/*   Updated: 2021/01/20 21:53:48 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tempstr;
	unsigned char	tofind;

	tempstr = (unsigned char*)str;
	tofind = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tempstr[i] == tofind)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
