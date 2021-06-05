/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:58:58 by ybong             #+#    #+#             */
/*   Updated: 2021/01/19 02:52:05 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*tempptr;

	i = 0;
	tempptr = (unsigned char *)ptr;
	while (i < num)
		tempptr[i++] = (unsigned char)value;
	return (ptr);
}
