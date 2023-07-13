/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:03:26 by mflury            #+#    #+#             */
/*   Updated: 2023/07/13 17:23:27 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push function.
void	ft_push(int *stacka, int *stackb, char *msg)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	finish;

	i = 0;
	finish = 0;
	if (!stacka[0])
		return ;
	tmp2 = stackb[i];
	while (stackb[i])
	{
		tmp1 = stackb[i + 1];
		stackb[i + 1] = tmp2;
		finish = tmp1;
		i++;
		tmp2 = stackb[i + 1];
		stackb[i + 1] = tmp1;
		finish = tmp2;
		i++;
	}
	stackb[i + 1] = finish;
	stackb[0] = stacka[0];
	i = 1;
	while (stacka[i])
	{
		stacka[i - 1] = stacka[i];
		i++;
	}
	stacka[i - 1] = 0;
	ft_printf("%s\n", msg);
}
