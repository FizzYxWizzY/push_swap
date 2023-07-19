/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:03:26 by mflury            #+#    #+#             */
/*   Updated: 2023/07/18 23:57:20 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push A sub-function.
void	ft_push_a(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->a[0])
		return ;
	data->tmp2 = stack->b[data->i];
	while (stack->b[data->i])
	{
		data->tmp1 = stack->b[data->i + 1];
		stack->b[data->i + 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i++;
		data->tmp2 = stack->b[data->i + 1];
		stack->b[data->i + 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i++;
	}
	stack->b[data->i + 1] = data->finish;
	stack->b[0] = stack->a[0];
	data->i = 1;
	while (stack->a[data->i])
	{
		stack->a[data->i - 1] = stack->a[data->i];
		data->i++;
	}
	stack->a[data->i - 1] = 0;
}

// push B sub-function.
void	ft_push_b(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->b[0])
		return ;
	data->tmp2 = stack->a[data->i];
	while (stack->a[data->i])
	{
		data->tmp1 = stack->a[data->i + 1];
		stack->a[data->i + 1] = data->tmp2;
		data->finish = data->tmp1;
		data->i++;
		data->tmp2 = stack->a[data->i + 1];
		stack->a[data->i + 1] = data->tmp1;
		data->finish = data->tmp2;
		data->i++;
	}
	stack->a[data->i + 1] = data->finish;
	stack->a[0] = stack->b[0];
	data->i = 1;
	while (stack->b[data->i])
	{
		stack->b[data->i - 1] = stack->b[data->i];
		data->i++;
	}
	stack->b[data->i - 1] = 0;
}

// push A/B function.
void	ft_push(t_stack *stack, t_data *data, char *msg)
{
	if (msg[1] == 'a')
		ft_push_a(stack, data);
	if (msg[1] == 'b')
		ft_push_b(stack, data);
	ft_printf("%s\n", msg);
}
