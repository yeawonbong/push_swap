/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:16:38 by ybong             #+#    #+#             */
/*   Updated: 2021/06/20 23:17:22 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_arg(int argc, char *argv[], t_stack *stack)
{
	int		i = 1;
	int 	j = 0;
	char	**temp=0;
	int 	atoied;
	char	*itoaed;

	if (argc < 2)
		error_exit(stack);
	while(i < argc)
	{
		temp = ft_split(argv[i++], ' '); //"1 23 4 이럴 경우를 염두, split"
		while (temp[j])
		{
			atoied = ft_atoi(temp[j]);
			if (ft_strlen(itoaed = ft_itoa(atoied)) != ft_strlen(temp[j]))
			{
				free(itoaed);
				error_exit(stack);
			}
			free(itoaed);
			stack->a = add_back(stack->a, stack->alen, atoied);
			(stack->alen)++;
			free(temp[j]);
			j++;
	 	}
		j = 0;
		free(temp);
	}
}

void	sort_arg(t_stack *stack, int size)
{
	int     *arr;
	int	temp;
	int	i;

	i = 0;
	if (!(arr = malloc(sizeof(int) * size)) || \
	!ft_memcpy(arr, stack->a, sizeof(int) * size))
		error_exit(stack);
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
		if (i == 0 || arr[i - 1] <= arr[i])
			i++;
		else
			i--;
	}
	stack->sorted_arr = arr;
	stack->sortedlen = stack->alen;
}

void	duplicates(t_stack *stack)
{
	int i;

	i = 1;
	while(i < stack->sortedlen)
	{
		if (stack->sorted_arr[i] == stack->sorted_arr[i - 1])
			error_exit(stack);
		i++;
	}   
}
