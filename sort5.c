/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:18:59 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:18:59 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		while ((*stack_a)->data != 0 && (*stack_a)->data != 1)
			exec_ra(stack_a);
		exec_pb(stack_a, stack_b);
		while ((*stack_a)->data != 0 && (*stack_a)->data != 1)
			exec_ra(stack_a);
		exec_pb(stack_a, stack_b);
		if ((*stack_b)->data == 0)
		{
			ft_printf("rb\n");
			mv_rotate(stack_b);
		}
		sort3(stack_a);
		exec_pa(stack_a, stack_b);
		exec_pa(stack_a, stack_b);
	}
}
