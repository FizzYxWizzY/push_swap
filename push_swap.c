/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/08/04 02:01:00 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack, t_data *data)
{
	if (ft_stklen(stack->a) <= 1)
		exit (0);
	else if (ft_stklen(stack->a) == 2)
		sort_two(stack, data);
	else if (ft_stklen(stack->a) == 3)
		sort_three(stack, data);
	else if (ft_stklen(stack->a) == 5)
		sort_five(stack, data);
	else
		radix_sort(stack, data);
}

void	var_init(t_data *data, t_stack *stack)
{
	data->i = 0;
	data->j = 0;
	data->tmp1 = 0;
	data->tmp2 = 0;
	data->finish = 0;
	stack->a = 0;
	stack->b = 0;
	stack->size = 0;
	data->min = 0;
}

void	arguments_checker(char **argv, t_stack *stack, t_data *data)
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
				error(stack, "invalids arguments");
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
}

int	is_int(char *num)
{
	if (ft_atoi(num) > INT_MAX || ft_atoi(num) < INT_MIN)
		return (0);
return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	stack;

	var_init(&data, &stack);
	if (argc < 2)
		exit (0);
	else if (argc == 2)
		spliter(argv[1], &stack, &data);
	else if (argc > 2)
	{
		arguments_checker(argv, &stack, &data);
		stack.a = ft_calloc(sizeof(int), (argc));
		if (!stack.a)
			error(&stack, "malloc failed");
		stack.b = ft_calloc(sizeof(int), (argc));
		if (!stack.b)
			error(&stack, "malloc failed");
		data.i = 1;
		while (argv[data.i])
		{
			if (!is_int(argv[data.i]))
				error(&stack, "argument too big for a int");
			stack.a[data.i - 1] = (int)ft_atoi(argv[data.i]);
			data.i++;
		}
		if (is_duplicated(&stack, &data))
 			error(&stack, "duplicated numbers detected");
	}
	ft_printf("IN:  A,B\n");
	data.i = 0;
while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i], stack.b[data.i]);
		data.i++;
	}
	search_and_replace(&stack, &data);
	
	sorting(&stack, &data);
	data.i = 0;
	ft_printf("OUT: A,B\n");
	while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i], stack.b[data.i]);
		data.i++;
	}
	free(stack.a);
	free(stack.b);
	return (0);
}