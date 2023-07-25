/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:49:56 by mflury            #+#    #+#             */
/*   Updated: 2023/07/16 00:49:56 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the stack contrains repeated numbers.
// returns 1 if there is a repeted number, 0 if not.
int	is_duplicated(t_stack *stack, t_data *data)
{
	data->i = 0;
	while (stack->a[data->i + 1])
	{
		data->j = data->i + 1;
		while (stack->a[data->j])
		{
			if (stack->a[data->i] != stack->a[data->j])
				data->j++;
			else
				return (1);
		}
		data->i++;
	}
	return (0);
}

// checks if the stack is sorted.
// returns 1 if the stack is sorted, 0 if not.
int	is_sorted(t_stack *stack, t_data *data)
{
	data->i = 0;
	while (stack->a[data->i + 1])
	{
		if (stack->a[data->i] < stack->a[data->i + 1])
			data->i++;
		else
			return (0);
	}
	return (1);
}

int	ft_stklen(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

// classic atoi.
//
// int	ft_atoi(const char *str)
// {
// 	int				res;
// 	int				sign;
// 	unsigned int	i;

// 	res = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 		{
// 			sign *= -1;
// 		}
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }
