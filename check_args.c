/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:41:32 by mflury            #+#    #+#             */
/*   Updated: 2023/08/06 23:41:32 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**args_init(int *argc, char *argv[], int *check)
{
	if (*argc == 1)
		exit(0);
	else if (*argc == 2)
	{
		*check = 1;
		argv = ft_split(argv[1], ' ');
		*argc = 0;
		while (argv[*argc])
			(*argc)++;
	}
	else
	{
		(*argc)--;
		argv++;
	}
	return (argv);
}

int	args_isvalid(int nbr_args, char *args[])
{
	int	i;
	int	j;

	i = 0;
	while (i < nbr_args)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	args_isunique(int nbr_args, char *args[])
{
	int	i;
	int	j;
	int	arg_to_int;

	i = 0;
	while (i < nbr_args)
	{
		arg_to_int = ft_atoi(args[i]);
		j = i + 1;
		while (j < nbr_args)
		{
			if (arg_to_int == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
