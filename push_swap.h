/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:47:09 by mflury            #+#    #+#             */
/*   Updated: 2023/07/19 17:08:48 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size;
}		t_stack;

typedef struct s_data
{
	int	i;
	int	j;
	int	tmp1;
	int	tmp2;
	int	finish;
}		t_data;

// int		ft_strlen(int *stack);
// int		ft_atoi(const char *str);
int		is_sorted(int *stack, t_data *data);
int		is_duplicated(int *stack, t_data *data);
int		error(t_stack *stack, char *msg);
int		ft_stklen(int *stack);

void	ft_swap(t_stack *stack, t_data *data, char *msg);
void	ft_push(t_stack *stack, t_data *data, char *msg);
void	ft_rotate(t_stack *stack, t_data *data, char *msg);
void	ft_reverse_rotate(t_stack *stack, t_data *data, char *msg);

void	sort_two(t_stack *stack, t_data *data);
void	sort_three(t_stack *stack, t_data *data);
void	sort_five(t_stack *stack, t_data *data);

#endif
