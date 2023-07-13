/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/13 19:21:45 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *msg)
{
	ft_printf("Error: %s.\n", msg);
	exit (0);
}

int	is_sorted(int *stack)
{
	int i;

	i = 0;
	while (stack[i + 1])
	{
		if(stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}


//
//
int	is_duplicated(int *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i + 1])
	{
		j = i + 1;
		while (stack[j])
		{
			if(stack[i] != stack[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}



int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int	*a;
	int	*b;
	
	if (argc < 3)
		error("nothing to sort");
	a = malloc((argc) * sizeof(int));
	b = malloc((argc) * sizeof(int));
	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				error("Invalid agruments");
			else
				j++;
		}
		j = 0;
		i++;
	}
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
	ft_printf("IN:  A,B\n");
	while (a[i])
	{
		ft_printf("     %d,%d\n", a[i],b[i]);
		i++;
	}
	
	// check duplicates
	//
	if (is_duplicated(a))
		error("duplicated numbers detected");

	// sort 2 numbers.
	if (argc == 3)
	{
		if (!is_sorted(a))
			ft_swap(a, b, "sa");
		return (0);
	}	

	// sort 3 numbers.
	//
	// 		1 2 3 ok
	// 1 3 2 sa + rra || sa + raa + ra
	// 		2 1 3 sa
	// 		2 3 1 ra
	// 		3 1 2 ra + ra || rra
	// 			3 2 1 sa + ra
	if (argc == 4)
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

	i = 0;
	ft_printf("OUT: A,B\n");
	while (a[i])
	{
		ft_printf("     %d,%d\n", a[i], b[i]);
		i++;
	}

	// ft_push(b, a, "pb");
	// i = 0;
	// while (a[i])
	// {
	// 	ft_printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_swap(a, b, "sa");
	// i = 0;
	// while (a[i])
	// {
	// 	ft_printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_push(a, b, "pa");
	// i = 0;
	// while (a[i])
	// {
	// 	ft_printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_push(a, b, "pa");
	// i = 0;
	// while (a[i])
	// {
	// 	ft_printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_rotate(b, "rb");
	// i = 0;
	// while (a[i])
	// {
	// 	ft_printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	free (a);
	free (b);
	return (0);
}
