/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:16:38 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 05:43:10 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicates(t_stack *stack)
{
	int i;

	i = 1;
	while (i < stack->sortedlen)
	{
		if (stack->sorted_arr[i] == stack->sorted_arr[i - 1])
			error_exit(stack);
		i++;
	}
}

void	atoi_error(t_stack *stack, int atoied, char *temp)
{
	char	*itoaed;

	if (ft_strlen(itoaed = ft_itoa(atoied)) != ft_strlen(temp))
	{
		free(itoaed);
		error_exit(stack);
	}
	free(itoaed);
}

void	get_arg(int argc, char *argv[], t_stack *stack)
{
	int		i;
	int		j;
	char	**temp;
	int		atoied;

	i = 1;
	temp = 0;
	if (argc < 2)
		error_exit(stack);
	while (i < argc)
	{
		j = 0;
		temp = ft_split(argv[i++], ' ');
		while (temp[j])
		{
			atoi_error(stack, atoied = ft_atoi(temp[j]), temp[j]);
			stack->a = add_back(stack->a, stack->alen, atoied);
			(stack->alen)++;
			free(temp[j]);
			j++;
		}
		free(temp);
	}
	sort_arg(stack, stack->alen);
	duplicates(stack);
}

void	sort_arg(t_stack *stack, int size)
{
	int	*arr;
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
