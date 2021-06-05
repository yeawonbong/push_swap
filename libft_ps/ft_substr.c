/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:59:54 by ybong             #+#    #+#             */
/*   Updated: 2021/01/22 02:32:02 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;

	if (!s || !(dst = (char *)malloc(len + 1)))
		return (0);
	if (start < ft_strlen(s))
	{
		src = (char*)&s[start];
		dst[len] = '\0';
		while (len--)
			dst[len] = src[len];
	}
	else
		*dst = '\0';
	return (dst);
}
