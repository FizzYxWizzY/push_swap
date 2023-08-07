/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:17:04 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:17:04 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	while (!is_sorted(stack_a))
	{
		first = *stack_a;
		last = (*stack_a)->next->next;
		if (first->data < last->data && first->next->data > last->data)
		{
			exec_sa(stack_a);
			exec_ra(stack_a);
		}
		else if (first->data > first->next->data && first->data < last->data)
			exec_sa(stack_a);
		else if (first->data > last->data && first->data < first->next->data)
			exec_rra(stack_a);
		else if (first->data > first->next->data && first->data > last->data)
			exec_ra(stack_a);
		else
		{
			exec_ra(stack_a);
			exec_sa(stack_a);
		}
	}
}
