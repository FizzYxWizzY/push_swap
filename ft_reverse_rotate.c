/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:36:59 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:36:59 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate function.
//
void	ft_reverse_rotate(int *stack, char *msg)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	finish;

	i = ft_strlen(stack);
	tmp1 = 0;
	tmp2 = 0;
	finish = 0;
	if (!stack[0])
		return ;
	tmp2 = stack[i];
	while (i >= 0)
	{
		if (i - 1 < 0)
			break ;
		tmp1 = stack[i - 1];
		stack[i - 1] = tmp2;
		finish = tmp1;
		i--;
		if (i - 1 < 0)
			break ;
		tmp2 = stack[i - 1];
		stack[i - 1] = tmp1;
		finish = tmp2;
		i--;
	}
	i = ft_strlen(stack);
	stack[i] = finish;
	printf("%s\n", msg);
}
