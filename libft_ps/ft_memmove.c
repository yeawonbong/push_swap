/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:21:08 by ybong             #+#    #+#             */
/*   Updated: 2021/01/06 04:41:31 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;

	tempdst = (unsigned char*)dst;
	tempsrc = (unsigned char*)src;
	i = 0;
	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		while (i < n)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			tempdst[n] = tempsrc[n];
	}
	return (dst);
}
