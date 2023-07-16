/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/16 02:17:25 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	error(char *msg)
// {
// 	ft_printf("Error: %s.\n", msg);
// 	exit (0);
// }

// int	is_sorted(int *stack)
// {
// 	int i;

// 	i = 0;
// 	while (stack[i + 1])
// 	{
// 		if(stack[i] < stack[i + 1])
// 			i++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }


// //
// //
// int	is_duplicated(int *stack)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (stack[i + 1])
// 	{
// 		j = i + 1;
// 		while (stack[j])
// 		{
// 			if(stack[i] != stack[j])
// 				j++;
// 			else
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }



// int	ft_atoi(const char *str)
// {
// 	int				res;
// 	int				sign;
// 	unsigned int	i;

// 	res = 0;
// 	sign = 1;
// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
// 			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 		{
// 			sign *= -1;
// 		}
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }

// sort 2 numbers.
void	sort_two(int *a, int *b)
{
	if (!is_sorted(a))
			ft_swap(a, b, "sa");
	exit (0);
}

// sort 3 numbers.
void	sort_three(int *a, int *b)
{
	while (!is_sorted(a))
	{
		if (a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
			ft_rotate(a, "ra");
		else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
			ft_reverse_rotate(a, "rra");
		else if (a[0] > a[1] && a[0] < a[2] && a[1] < a[2])
			ft_swap(a, b, "sa");
		else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
		{
			ft_swap(a, b, "sa");
			ft_rotate(a, "ra");
		}
		else if (a[0] < a[1] && a[1] > a[2] && a[1] < a[2])
		{
			ft_swap(a, b, "sa");
			ft_reverse_rotate(a, "rra");
		}
	}
}

// sort 5 numbers.
//

// checks if all the arguments are integers.
//
int	is_integers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int	i;
	int	*a;
	int	*b;
	
	if (argc < 3)
		error("nothing to sort");
	a = malloc((argc) * sizeof(int));
	if (!a)
		error("malloc failed (stack a)");
	b = malloc((argc) * sizeof(int));
	if (!b)
		error("malloc failed (stack b)");
	if (!is_integers(argv))
		error("invalids arguments");
	i = 1;
	while (i < argc)
	{
		a[i - 1] = ft_atoi(argv[i]);
		b[i - 1] = 0;
		i++;
	}
	a[i - 1] = '\0';
	b[i - 1] = '\0';
	i = 0;
	if (is_duplicated(a))
		error("duplicated numbers detected");
	ft_printf("IN:  A,B\n");
	while (a[i])
	{
		ft_printf("     %d,%d\n", a[i],b[i]);
		i++;
	}
	// sorting tree.
	if (argc == 3)
		sort_two(a, b);
	else if (argc == 4)
		sort_three(a, b);
	// else if (argc == 6)
	// 	sort_five(a, b);
	i = 0;
	ft_printf("OUT: A,B\n");
	while (a[i])
	{
		ft_printf("     %d,%d\n", a[i], b[i]);
		i++;
	}
	free (a);
	free (b);
	return (0);
}
