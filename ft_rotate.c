/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:35:20 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:35:20 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate A sub-function.
void	ft_rotate_a(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->a[0])
		return ;
	data->tmp2 = stack->a[data->i];
	while (stack->a[data->i])
	{
		if (!stack->a[data->i + 1])
			break ;
		data->tmp1 = stack->a[data->i + 1];
		stack->a[data->i + 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i++;
		if (!stack->a[data->i + 1])
			break ;
		data->tmp2 = stack->a[data->i + 1];
		stack->a[data->i + 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i++;
	}
	stack->a[0] = data->finish;
}

// rotate B sub-function.
void	ft_rotate_b(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->b[0])
		return ;
	data->tmp2 = stack->a[data->i];
	while (stack->b[data->i])
	{
		if (!stack->b[data->i + 1])
			break ;
		data->tmp1 = stack->b[data->i + 1];
		stack->b[data->i + 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i++;
		if (!stack->b[data->i + 1])
			break ;
		data->tmp2 = stack->b[data->i + 1];
		stack->b[data->i + 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i++;
	}
	stack->b[0] = data->finish;
}

// rotate function.
// ra, rb, rr.
void	ft_rotate(t_stack *stack, t_data *data, char *msg)
{
	if (msg[1] == 'a')
		ft_rotate_a(stack, data);
	if (msg[1] == 'b') 
		ft_rotate_b(stack, data);
	if (msg[1] == 'r')
	{
		ft_rotate_a(stack, data);
		ft_rotate_b(stack, data);
	}
	ft_printf("%s\n", msg);
}
