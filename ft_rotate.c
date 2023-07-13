/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:35:20 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:35:20 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate function.
//
void	ft_rotate(int *stack, char *msg)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	finish;

	i = 0;
	finish = 0;
	if (!stack[0])
		return ;
	tmp2 = stack[i];
	while (stack[i])
	{
		if (!stack[i + 1])
			break ;
		tmp1 = stack[i + 1];
		stack[i + 1] = tmp2;
		finish = tmp1;
		i++;
		if (!stack[i + 1])
			break ;
		tmp2 = stack[i + 1];
		stack[i + 1] = tmp1;
		finish = tmp2;
		i++;
	}
	stack[0] = finish;
	ft_printf("%s\n", msg);
}
