/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:48:49 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:48:49 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkpop(t_stack **stack)
{
	t_stack	*tmp;
	int		resp;

	if (ft_stkisempty(*stack))
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	resp = tmp->data;
	free(tmp);
	return (resp);
}
