/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:32:26 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:32:26 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap A sub-function.
void	ft_swap_a(t_stack *stack, t_data *data)
{
	if (!stack->a[0] || !stack->a[1])
		return ;
	data->tmp1 = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = data->tmp1;
}

// swap B sub-function.
void	ft_swap_b(t_stack *stack, t_data *data)
{
	if (!stack->b[0] || !stack->b[1])
		return ;
	data->tmp1 = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = data->tmp1;
}

// swap function.
// sa, sb, ss.
void	ft_swap(t_stack *stack, t_data *data, char *msg)
{
	if (msg[1] == 'a')
		ft_swap_a(stack, data);
	if (msg[1] == 'b')
		ft_swap_b(stack, data);
	if (msg[1] == 's')
	{
		ft_swap_a(stack, data);
		ft_swap_b(stack, data);
	}
	ft_printf("%s\n", msg);
}
