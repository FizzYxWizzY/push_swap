/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:39:24 by mflury            #+#    #+#             */
/*   Updated: 2023/07/21 00:07:30 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

    // 1 -> 2 -> 3 = OK.
    // 1 -> 3 -> 2 = [0] < [1] > [2] && [0] < [2] = ra + sa = OK.
    // 2 -> 1 -> 3 = [0] > [1] < [2] && [0] < [2] = sa = OK.
    // 2 -> 3 -> 1 = [0] < [1] > [2] && [0] > [2] = ra = OK.
    // 3 -> 1 -> 2 = [0] > [1] < [2] && [0] > [2] = rra = OK.
    // 3 -> 2 -> 1 = [0] > [1] > [2] && [0] > [2] = rra + sa = OK.

// sort 3 numbers.
void	sort_three(t_stack *stack, t_data *data)
{
	if (!is_sorted(stack, data))
	{
		if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[0] < stack->a[2])
		{
			ft_rotate(stack, data, "ra");
			ft_swap(stack, data, "sa");
		}
		else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
			&& stack->a[0] < stack->a[2])
			ft_swap(stack, data, "sa");
		else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[0] > stack->a[2])
			ft_rotate(stack, data, "ra");
		else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
			&& stack->a[0] > stack->a[2])
			ft_reverse_rotate(stack, data, "rra");
		else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2]
			&& stack->a[0] > stack->a[2])
		{
			ft_reverse_rotate(stack, data, "rra");
			ft_swap(stack, data, "sa");
		}
	}
}
