/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:47:59 by mflury            #+#    #+#             */
/*   Updated: 2023/08/01 18:53:19 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spliter(char *argv, t_stack *stack, t_data *data)
{
	char	**splited;
	int		i;

	// (void) data;
	i = 0;
	splited = ft_split(argv, ' ');
	arguments_checker(splited, stack, data);
	while (splited[i])
	{
		if (!is_int(splited[i]))
			error(stack, "invalids arguments");
		i++;
	}
	if (i < 2)
		error(stack, "too few arguments");
	stack->a = ft_calloc(sizeof(int), i + 1);
	stack->b = ft_calloc(sizeof(int), i + 1);
	i = 0;
	while (splited[i])
	{
		stack->a[i] = (int)ft_atoi(splited[i]);
		stack->b[i] = 0;
		free(splited[i]);
		i++;
	}
	free(splited);
}
