/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:51:56 by mflury            #+#    #+#             */
/*   Updated: 2023/07/16 00:51:56 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack *stack, char *msg)
{
	ft_printf("Error: %s.\n", msg);
	if (stack->a)
	{
		free (stack->a);
		stack->a = NULL;
	}
	if (stack->b)
	{
		free (stack->b);
		stack->b = NULL;
	}
	exit (0);
}
