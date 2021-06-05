/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:38:18 by ybong             #+#    #+#             */
/*   Updated: 2021/01/31 03:42:46 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_height(char const *s, char c)
{
	int		count;

	count = 0;
	if (*s != c && *s)
		count++;
	while ((s = ft_strchr(s, (int)c)) != 0 && *s)
	{
		if (s[1] && s[1] != c)
			count++;
		s++;
	}
	return (count);
}

static int	ft_count_width(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
		if (*s == c)
			break ;
	}
	return (count);
}

static char	ft_fill_arr(char const *s, char c, int i, char **arr)
{
	int j;

	j = 0;
	while (!(s[j] == c) && s[j])
	{
		arr[i][j] = s[j];
		j++;
	}
	arr[i][j] = '\0';
	return (0);
}

static char	**ft_free_mem(char **arr, int current)
{
	int i;

	i = 0;
	while (i < current)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		height;
	int		i;

	if (!s)
		return (0);
	height = ft_count_height(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (height + 1))))
		return (0);
	arr[height] = NULL;
	i = 0;
	while (i < height)
	{
		while (*s == c)
			s++;
		if (!(arr[i] = malloc(sizeof(char) * (ft_count_width(s, c) + 1))))
			return (ft_free_mem(arr, i));
		ft_fill_arr(s, c, i, arr);
		if (ft_strchr(s, (int)c))
			s = ft_strchr(s, (int)c);
		i++;
	}
	return (arr);
}
