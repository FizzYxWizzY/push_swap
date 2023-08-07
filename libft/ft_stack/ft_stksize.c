/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:49:35 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:49:35 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stksize(t_stack *stack)
{
	int	resp;

	resp = 0;
	while (stack)
	{
		resp++;
		stack = stack->next;
	}
	return (resp);
}
