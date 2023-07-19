/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:36:59 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:36:59 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate A sub-function.
void	ft_reverse_rotate_a(t_stack *stack, t_data *data)
{
	data->i = ft_strlen(stack->a);
	data->tmp1 = 0;
	data->tmp2 = 0;
	data->finish = 0;
	if (!stack->a[0])
		return ;
	data->tmp2 = stack->a[data->i];
	while (data->i >= 0)
	{
		if (data->i - 1 < 0)
			break ;
		data->tmp1 = stack->a[i - 1];
		stack->a[i - 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i--;
		if (data->i - 1 < 0)
			break ;
		data->tmp2 = stack->a[i - 1];
		stack->a[i - 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i--;
	}
	data->i = ft_strlen(stack->a);
	stack->a[data->i] = data->finish;
}

// reverse rotate B sub-function.
void	ft_reverse_rotate_b(t_stack *stack, t_data *data)
{
	data->i = ft_strlen(stack->b);
	data->tmp1 = 0;
	data->tmp2 = 0;
	data->finish = 0;
	if (!stack->b[0])
		return ;
	data->tmp2 = stack->b[data->i];
	while (data->i >= 0)
	{
		if (data->i - 1 < 0)
			break ;
		data->tmp1 = stack->b[i - 1];
		stack->b[i - 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i--;
		if (data->i - 1 < 0)
			break ;
		data->tmp2 = stack->b[i - 1];
		stack->a[i - 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i--;
	}
	data->i = ft_strlen(stack->b);
	stack->b[data->i] = data->finish;
}

// reverse rotate function.
// rra, rrb, rrr.
void	ft_reverse_rotate(t_stack *stack, t_data *data, char *msg)
{
	if (msg[2] == 'a')
		ft_reverse_rotate_a(stack, data);
	if (msg[2] == 'b')
		ft_reverse_rotate_b(stack, data);
	if (msg[2] == 'r')
	{
		ft_reverse_rotate_a(stack, data);
		ft_reverse_rotate_b(stack, data);
	}
	else
		return ;
	ft_printf("%s\n", msg);
}
