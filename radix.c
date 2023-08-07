/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:53:45 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 18:01:46 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	iterations;
	int	size;

	i = 0;
	size = ft_stksize(*stack_a);
	while (!is_sorted(stack_a))
	{
		iterations = 0;
		while (iterations < size)
		{
			if ((((*stack_a)->data >> i) & 1))
				exec_ra(stack_a);
			else
				exec_pb(stack_a, stack_b);
			iterations++;
		}
		while (ft_stksize(*stack_b) > 0)
			exec_pa(stack_a, stack_b);
		i++;
	}
}
