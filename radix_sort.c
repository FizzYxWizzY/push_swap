/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:11:51 by mflury            #+#    #+#             */
/*   Updated: 2023/08/04 02:51:00 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack, t_data *data)
{
	int	i;
	int	j;
	int	size;
	
	i = 0;
	ft_printf ("[0] = %d\n", stack->a[0]);
	size = ft_stklen(stack->a);
	while (!is_sorted(stack, data))
	{
		j = 0;
		while (j < size)
		{
			if (((stack->a[0] >> i) & 1) == 0)
				ft_push(stack, data, "pa");
			else
				ft_rotate(stack, data, "ra");
			ft_printf ("j = %d\n", j);
			j++;
		}
		while (stack->b[0])
			ft_push(stack, data, "pb");
		i++;
		ft_printf ("i = %d\n", i);
		data->i = 0;
		while (stack->a[data->i])
		{
			ft_printf("     %d,%d\n", stack->a[data->i], stack->b[data->i]);
			data->i++;
		}
		// sleep(2);
		if (i == 1000)
			break ;
	}
}
