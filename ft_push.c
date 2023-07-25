/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:03:26 by mflury            #+#    #+#             */
/*   Updated: 2023/07/21 02:02:39 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push A sub-function.
int	ft_push_a(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->a[0])
		return (0);
	data->tmp2 = stack->b[data->i];
	while (stack->b[data->i])
	{
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
	stack->b[data->i + 1] = data->finish;
	stack->b[0] = stack->a[0];
	data->i = 1;
	while (stack->a[data->i])
	{
		stack->a[data->i - 1] = stack->a[data->i];
		data->i++;
	}
	stack->a[data->i - 1] = 0;
	return (1);
}

// push B sub-function.
int	ft_push_b(t_stack *stack, t_data *data)
{
	data->i = 0;
	data->finish = 0;
	if (!stack->b[0])
		return (0);
	data->tmp2 = stack->a[data->i];
	while (stack->a[data->i])
	{
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
	stack->a[data->i + 1] = data->finish;
	stack->a[0] = stack->b[0];
	data->i = 1;
	while (stack->b[data->i])
	{
		stack->b[data->i - 1] = stack->b[data->i];
		data->i++;
	}
	stack->b[data->i - 1] = 0;
	return (1);
}

// push A/B function.
void	ft_push(t_stack *stack, t_data *data, char *msg)
{
	if (msg[1] == 'a')
		if (ft_push_a(stack, data))
			ft_printf("%s\n", msg);
	if (msg[1] == 'b')
		if(ft_push_b(stack, data))
			ft_printf("%s\n", msg);
}
