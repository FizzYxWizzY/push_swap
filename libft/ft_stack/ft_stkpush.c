/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:49:14 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:49:14 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stkpush(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = ft_stknew(data);
	new_node->next = *stack;
	*stack = new_node;
}
