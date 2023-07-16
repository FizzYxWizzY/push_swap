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
int	is_duplicated(int *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i + 1])
	{
		j = i + 1;
		while (stack[j])
		{
			if(stack[i] != stack[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

// checks if the stack is sorted.
// returns 1 if the stack is sorted, 0 if not.
int	is_sorted(int *stack)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if(stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

// 
//
int	ft_strlen(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

// classic atoi.
//
int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
