/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_norme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:17:05 by mflury            #+#    #+#             */
/*   Updated: 2023/08/01 18:53:18 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_next_index_min(t_stack *stack, t_data *data)
{
	int i;
	int nextmin;

	i = 0;
	nextmin = INT_MAX;
	while (stack->a[i])
	{
		if (stack->a[i] < nextmin && stack->a[i] > data->min)
			nextmin = stack->a[i];
		i++;
	}
	
	i = 0;
	while (stack->a[i] != nextmin)
		i++;
	data->min = nextmin;
	return (i);
}

int	search_index_min(t_stack *stack, t_data *data)
{
	int i;

	i = 0;
	data->min = INT_MAX;
	while (stack->a[i])
	{
		if (stack->a[i] < data->min)
			data->min = stack->a[i];
		i++;
	}
	i = 0;
	while (stack->a[i] != data->min)
		i++;
	return (i);
}

void	search_and_replace(t_stack *stack, t_data *data)
{
	int	*tmp;
	int	i;
	int	count;

	count = 1;
	tmp = malloc(ft_stklen(stack->a) * sizeof(int));
	if (!tmp)
		error(stack, "malloc failed (tmp)");
	tmp[ft_stklen(stack->a) - 1] = 0;
	
	i = search_index_min(stack, data);
	tmp[i] = count;
	count++;
	while (count <= ft_stklen(stack->a))
	{
		i = search_next_index_min(stack, data);
		tmp[i] = count;
		count++;
	}
	i = 0;

	while (stack->a[i])
	{
		stack->a[i] = tmp[i];
		i++;
	}
	free(tmp);
}



