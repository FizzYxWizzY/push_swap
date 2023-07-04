/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/04 23:56:06 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *msg)
{
	printf("Error: %s.\n", msg);
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
		exit (0);
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
	a[i + 2] = '\0';
	b[i + 2] = '\0';
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i],b[i]);
		i++;
	}
	
	// sort 2 numbers.
	if (argc == 3)
	{
		if (!is_sorted(a))
			ft_swap(a, b, "sa");

	}	

	// sort 3 numbers.
	// if (argc == 4)
	// {
	// 	printf("plop 1");
	// 	while (!is_sorted(a))
	// 	{
	// 		if (a[0] < a[1] && a[2] < a[0])
	// 			ft_rotate(a, "ra");
	// 		else
	// 			break ;
	// 	}
		
	// }

	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i],b[i]);
		i++;
	}

	// b[0] = 123;
	// ft_push(b, a, "pb");
	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_swap(a, b, "sa");
	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_push(a, b, "pa");
	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_push(a, b, "pa");
	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	// ft_rotate(b, "rb");
	// i = 0;
	// while (a[i])
	// {
	// 	printf("%d,%d\n", a[i], b[i]);
	// 	i++;
	// }
	free (a);
	free (b);
	return (0);
}
