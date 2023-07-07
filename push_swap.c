/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/03 15:59:56 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	*a;
	int	*b;

	a = malloc((argc + 2) * sizeof(int));
	b = malloc((argc + 2) * sizeof(int));
	i = 1;
	if (argc < 3)
		return (1);
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
	b[0] = 123;
	ft_push(b, a, "pb");
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i], b[i]);
		i++;
	}
	ft_swap(a, b, "sa");
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i], b[i]);
		i++;
	}
	ft_push(a, b, "pa");
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i], b[i]);
		i++;
	}
	ft_push(b, a, "pb");
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i], b[i]);
		i++;
	}
	ft_rotate(a, "ra");
	i = 0;
	while (a[i])
	{
		printf("%d,%d\n", a[i], b[i]);
		i++;
	}
	return (0);
}
