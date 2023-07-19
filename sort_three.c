/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:39:24 by mflury            #+#    #+#             */
/*   Updated: 2023/07/19 16:41:54 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort 3 numbers.
void	sort_three(t_stack *stack, t_data *data)
{
	while (!is_sorted(stack, data))
	{
		if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[2] < stack->a[0])
			ft_rotate(stack, data, "ra");
		else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
			&& stack->a[0] > stack->a[2])
			ft_reverse_rotate(stack, data, "rra");
		else if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
			&& stack->a[1] < stack->a[2])
			ft_swap(stack, data, "sa");
		else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[0] > stack->a[2])
		{
			ft_swap(stack, data, "sa");
			ft_rotate(stack, data, "ra");
		}
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[1] < stack->a[2])
		{
			ft_swap(stack, data, "sa");
			ft_reverse_rotate(stack, data, "rra");
		}
	}
}
