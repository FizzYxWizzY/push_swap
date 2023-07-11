/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:47:09 by mflury            #+#    #+#             */
/*   Updated: 2023/07/11 15:52:07 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"

void	ft_swap(int *a, int *b, char *msg);
void	ft_push(int *stacka, int *stackb, char *msg);
void	ft_rotate(int *stack, char *msg);
void	ft_reverse_rotate(int *stack, char *msg);


#endif
