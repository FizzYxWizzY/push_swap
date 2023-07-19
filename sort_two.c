/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:38:15 by mflury            #+#    #+#             */
/*   Updated: 2023/07/19 16:41:44 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort 2 numbers.
void	sort_two(t_stack *stack, t_data *data)
{
	if (!is_sorted(stack, data))
		ft_swap(stack, data, "sa");
}
