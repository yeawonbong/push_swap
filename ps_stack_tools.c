/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:25:12 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 03:26:55 by ybong            ###   ########.fr       */
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

void	totop_if(char toswap, t_stack *stack, char stacknum)
{
	int		**st;
	void	(*swap)(t_stack *stack);

	st = stacknum == 'a' ? &stack->a : &stack->b;
	swap = stacknum == 'a' ? sa : sb;
	if (BIGGER == toswap && (*st)[0] < (*st)[1])
		swap(stack);
	if (SMALLER == toswap && (*st)[0] > (*st)[1])
		swap(stack);
}

void	tobottom_if(char tobottom, t_stack *stack, char stacknum)
{
	void	(*rotate)(t_stack *stack);

	rotate = stacknum == 'a' ? ra : rb;
	totop_if(tobottom, stack, stacknum);
	rotate(stack);
}
