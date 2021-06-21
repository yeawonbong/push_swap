/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:16:38 by ybong             #+#    #+#             */
/*   Updated: 2021/06/21 20:49:43 by ybong            ###   ########.fr       */
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

void	non_int(t_stack *stack, char **temp, int j)
{
	int	i;

	i = 0;
	while (temp[j][i])
	{
		if (temp[j][i] == '-')
			i++;
		if (!ft_isdigit(temp[j][i]))
		{
			free(temp[j]);
			free(temp);
			error_exit(stack);
		}
		i++;
	}
}

void	atoi_error(t_stack *stack, int atoied, char *temp)
{
	char	*itoaed;

	while (*temp == '0' && *(temp + 1))
		temp++;
	if (ft_strlen(itoaed = ft_itoa(atoied)) != ft_strlen(temp))
	{
		free(itoaed);
		error_exit(stack);
	}
	free(itoaed);
}

int		cmp_arr(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->sortedlen)
	{
		if (stack->a[i] == stack->sorted_arr[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	get_arg(int argc, char *argv[], t_stack *stack)
{
	int		i;
	int		j;
	char	**temp;
	int		atoied;

	i = 1;
	temp = 0;
	while (i < argc)
	{
		if (!*argv[i])
			error_exit(stack);
		j = 0;
		temp = ft_split(argv[i++], ' ');
		while (temp[j])
		{
			non_int(stack, temp, j);
			atoi_error(stack, atoied = ft_atoi(temp[j]), temp[j]);
			stack->a = add_back(stack->a, stack->alen, atoied);
			(stack->alen)++;
			free(temp[j]);
			j++;
		}
		free(temp);
	}
	sort_arg(stack, stack->alen);
}
