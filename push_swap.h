/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:35:09 by mflury            #+#    #+#             */
/*   Updated: 2023/06/03 02:35:09 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"

typedef struct		s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;



#endif
