/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:45:38 by mflury            #+#    #+#             */
/*   Updated: 2023/08/06 23:45:38 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_swap(t_stack **stack)
{
	int	res1;
	int	res2;

	if (ft_stksize(*stack) >= 2)
	{
		res1 = ft_stkpop(stack);
		res2 = ft_stkpop(stack);
		ft_stkpush(stack, res1);
		ft_stkpush(stack, res2);
	}
}

void	mv_push(t_stack **stack1, t_stack **stack2)
{
	int	res;

	if (!ft_stkisempty(*stack2))
	{
		res = ft_stkpop(stack2);
		ft_stkpush(stack1, res);
	}
}

void	mv_rotate(t_stack **stack)
{
	int		res;
	t_stack	*new_node;
	t_stack	*tmp;

	if (ft_stksize(*stack) >= 2)
	{
		res = ft_stkpop(stack);
		new_node = ft_stknew(res);
		tmp = (*stack);
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new_node;
		(*stack) = tmp;
	}
}

void	mv_rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	new_last = ft_stknew(last->data);
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	free(last->next);
	last->next = NULL;
	new_last->next = *stack;
	*stack = new_last;
}
