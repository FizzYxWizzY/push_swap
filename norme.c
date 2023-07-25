/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:12:01 by mflury            #+#    #+#             */
/*   Updated: 2023/07/24 19:05:25 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"









// int	is_min(t_stack *stack, int *tmp)
// {
// 	int	i;
// 	int min;

// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		if (stack->a[i] == min)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	find_min(t_stack *stack, t_data *data)
// {
// 	int	*tmp;
// 	int	min;
// 	int	count;

// 	count = 1;
// 	min = stack->a[0];
// 	tmp = malloc(ft_stklen(stack->a) * sizeof(int));
// 	if (!tmp)
// 		error(stack, "malloc failed (tmp)");
// 	tmp[ft_stklen(stack->a)] = '\0';
// 	data->i = 0;
// 	while (stack->a[data->i])
// 	{
// 		if (stack->a[data->i] < min)
// 			min = stack->a[data->i];
// 		data->i++;
// 	}
// 	data->i = 0;
// 	while (stack->a[data->i] != min)
// 		data->i++;
// 	tmp[data->i] = count;
// 	data->i = 0;
// 	count++;
// 	min++;
// 	while (min < INT_MAX)
// 	{
// 		while (stack->a[data->i] && stack->a[data->i] != min)
// 			data->i++;
// 		if (stack->a[data->i] == min)
// 			tmp[data->i] = count;
// 		count++;
// 		data->i = 0;
// 		min++;	
// 	}
// }





// // a function that find the smallest number in a stack,
// // and replace it with its place on the stack,
// // for example 30, 40, 5, 112. -> 2, 3, 1, 4.
// void	norme(t_stack *stack)
// {
// 	int		i;
// 	int		j;
// 	int		min;
// 	int		*tab;

// 	i = 0;
// 	j = 0;
// 	tab = malloc(sizeof(int) * stack->size);
// 	while (i < stack->size)
// 	{
// 		tab[i] = stack->tab[i];
// 		i++;
// 	}
// 	while (j < stack->size)
// 	{
// 		min = find_min(tab, stack->size);
// 		stack->tab[j] = min;
// 		tab[min] = -1;
// 		j++;
// 	}
// 	free(tab);
// } 