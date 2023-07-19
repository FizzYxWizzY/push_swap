/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:40:30 by mflury            #+#    #+#             */
/*   Updated: 2023/07/19 16:43:24 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort 5 numbers.
void	sort_five(t_stack *stack, t_data *data)
{
	data->i = 0;
	while (data->i < 2)
	{
		if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
			&& stack->a[0] < stack->a[3]
			&& (stack->a[0] < stack->a[4] || !stack->a[4]))
		{
			ft_push(stack, data, "pa");

		}
		else
			ft_rotate(stack, data, "ra");
		data->i++;
	}
	sort_three(stack, data);
	ft_push(stack, data, "pb");
	ft_push(stack, data, "pb");
}
