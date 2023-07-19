/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/19 03:01:34 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_data *data, t_stack *stack)
{
	if (ft_strlen(stack->a) < 1)
		exit (0);
	else if (ft_strlen(stack->a) == 2)
		sort_two(stack, data);
	else if (ft_strlen(stack->a) == 3)
		sort_three(stack, data);
	else if (ft_strlen(stack->a) == 5)
		sort_five(stack, data);
	// else if (ft_strlen(stack->a) == 100)
	// 	sort_hundred(data, stack);
	// else if (ft_strlen(stack->a) == 500)
	// 	sort_five_hundred(data, stack);
}

void	var_init(t_data *data, t_stack *stack)
{
	data->i = 0;
	data->j = 0;
	data->tmp1 = 0;
	data->tmp2 = 0;
	data->finish = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 0;
}

void	arguments_checker(char **argv, t_data *data)
{
	data->i = 1;
	data->j = 0;
	while (argv[data->i])
	{
		if (argv[data->i][0] == '-')
			data->j++;
		while (argv[data->i][data->j])
		{
			if (argv[data->i][data->j] < '0' || argv[data->i][data->j] > '9')
				error("invalids arguments");
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	stack;

	arguments_checker(argv, &data);
	stack.size = argc;
	sorting(&data, &stack);
	stack.a = malloc(argc * sizeof(int));
	if (!stack.a)
		error("malloc failed (stack a)");
	stack.b = malloc(argc * sizeof(int));
	if (!stack.b)
		error("malloc failed (stack b)");
	data.i = 1;
	while (data.i < argc)
	{
		stack.a[data.i - 1] = ft_atoi(argv[data.i]);
		stack.b[data.i - 1] = 0;
		data.i++;
	}
	stack.a[data.i - 1] = '\0';
	stack.b[data.i - 1] = '\0';
	data.i = 0;
	if (is_duplicated(a))
		error("duplicated numbers detected");
	ft_printf("IN:  A,B\n");
	while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i],stack.b[data.i]);
		data.i++;
	}

	data.i = 0;
	ft_printf("OUT: A,B\n");
	while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i], stack.b[data.i]);
		data.i++;
	}
	free (a);
	free (b);
	return (0);
}
