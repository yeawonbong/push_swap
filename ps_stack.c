/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:31:55 by ybong             #+#    #+#             */
/*   Updated: 2021/06/09 21:31:55 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*add_front(int *arr, int len, int new)
{
	int	*temp;

	if (!arr)
	{
		temp = malloc(sizeof(int));
		*temp = new;
	}
	else
	{
		temp = malloc(sizeof(int) * (len + 1));
		ft_memmove(&temp[1], arr, sizeof(int) * len);
		free(arr);
		temp[0] = new;
	}
	return (temp);
}

int		*add_back(int *arr, int len, int new)
{
	int	*temp;

	temp = NULL;
	if (!arr)
	{
		temp = malloc(sizeof(int));
		*temp = new;
	}
	else
	{
		temp = malloc(sizeof(int) * (len + 1));
		temp = ft_memcpy(temp, arr, sizeof(int) * len);
		free(arr);
		temp[len] = new;
	}
	return (temp);
}

int		*del_front(int *arr, int len)
{
	int	*temp;

	temp = NULL;
	if (!arr)
		return (arr);
	temp = malloc(sizeof(int) * (len - 1));
	temp = ft_memcpy(temp, &arr[1], sizeof(int) * (len - 1));
	free(arr);
	return (temp);
}
