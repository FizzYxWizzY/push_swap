/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:32:26 by mflury            #+#    #+#             */
/*   Updated: 2023/07/12 05:32:26 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap function.
// sa, sb, ss.
void	ft_swap(int *stacka, int *stackb, char *msg)
{
	int	tmp;

	if (msg[1] == 'a')
	{
		if (!stacka[1])
			return ;
		tmp = stacka[1];
		stacka[1] = stacka[0];
		stacka[0] = tmp;
	}
	else if (msg[1] == 'b')
	{
		if (!stackb[1])
			return ;
		tmp = stackb[1];
		stackb[1] = stackb[0];
		stackb[0] = tmp;
	}
	else
	{
		if (!stacka[1] || !stackb[1])
			return ;
		tmp = stacka[1];
		stacka[1] = stacka[0];
		stacka[0] = tmp;
		tmp = stackb[1];
		stackb[1] = stackb[0];
		stackb[0] = tmp;
	}
	ft_printf("%s\n", msg);
}
