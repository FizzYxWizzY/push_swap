/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:51:55 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:51:55 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;

	while (*lst)
	{
		el = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = el;
	}
	free(*lst);
	*lst = NULL;
}
