/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/24 19:20:27 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack, t_data *data)
{
	if (ft_stklen(stack->a) < 1)
		exit (0);
	else if (ft_stklen(stack->a) == 2)
		sort_two(stack, data);
	else if (ft_stklen(stack->a) == 3)
		sort_three(stack, data);
	else if (ft_stklen(stack->a) == 5)
		sort_five(stack, data);
	// else if (ft_stklen(stack->a) == 100)
	// 	sort_hundred(data, stack);
	// else if (ft_stklen(stack->a) == 500)
	// 	sort_five_hundred(data, stack);
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

int	is_int(char **argv, t_data *data)
{
	data->i = 1;
	while (argv[data->i])
	{
		if (ft_atoi(argv[data->i]) > INT_MAX || ft_atoi(argv[data->i]) < INT_MIN)
			return (0);
		data->i++;
	}
	return (1);
}

// q: at what time do we go to sleep?
// a: when we have sorted the stack.
// q: really?
// a: yes.
// q: what if we have not sorted the stack?
// a: then we do not go to sleep.
// q: but... please
// a: no.
// q: but...
// a: no.
// q: but...
// a: no.

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	stack;

	var_init(&data, &stack);
	arguments_checker(argv, &stack, &data);
	if (!is_int(argv, &data))
		error(&stack, "arguments too big for a int");
	stack.a = malloc(argc * sizeof(int));
	if (!stack.a)
		error(&stack, "malloc failed (stack a)");
	stack.b = malloc(argc * sizeof(int));
	if (!stack.b)
		error(&stack, "malloc failed (stack b)");
	data.i = 1;
	while (data.i < argc)
	{
		stack.a[data.i - 1] = (int)ft_atoi(argv[data.i]);
		stack.b[data.i - 1] = 0;
		data.i++;
	}
	stack.a[data.i - 1] = '\0';
	stack.b[data.i - 1] = '\0';
	data.i = 0;
	if (is_duplicated(&stack, &data))
		error(&stack, "duplicated numbers detected");
	
	ft_printf("IN:  A,B\n");
	data.i = 0;
	while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i], stack.b[data.i]);
		data.i++;
	}
	search_and_replace(&stack, &data);
	data.i = 0;
	ft_printf("OUT: A,B\n");
	while (stack.a[data.i])
	{
		ft_printf("     %d,%d\n", stack.a[data.i], stack.b[data.i]);
		data.i++;
	}
	free (stack.a);
	free (stack.b);
	return (0);
}
