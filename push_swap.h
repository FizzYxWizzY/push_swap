/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:47:09 by mflury            #+#    #+#             */
/*   Updated: 2023/08/04 01:47:31 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "limits.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"

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
	int	min;
	int	tmp1;
	int	tmp2;
	int	finish;
}		t_data;

int		is_int(char *num);
int		is_sorted(t_stack *stack, t_data *data);
int		is_duplicated(t_stack *stack, t_data *data);
int		error(t_stack *stack, char *msg);
int		ft_stklen(int *stack);
void	search_and_replace(t_stack *stack, t_data *data);
void	spliter(char *argv, t_stack *stack, t_data *data);

void	arguments_checker(char **argv, t_stack *stack, t_data *data);

void	ft_swap(t_stack *stack, t_data *data, char *msg);
void	ft_push(t_stack *stack, t_data *data, char *msg);
void	ft_rotate(t_stack *stack, t_data *data, char *msg);
void	ft_reverse_rotate(t_stack *stack, t_data *data, char *msg);

void	sort_two(t_stack *stack, t_data *data);
void	sort_three(t_stack *stack, t_data *data);
void	sort_five(t_stack *stack, t_data *data);
void	radix_sort(t_stack *stack, t_data *data);

#endif
