/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:54:19 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:54:19 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resp;
	t_list	*el;

	if (!f || !del || !del)
		return (NULL);
	resp = NULL;
	while (lst)
	{
		el = ft_lstnew(f(lst->content));
		if (el == NULL)
		{
			ft_lstclear(&resp, del);
			return (NULL);
		}
		ft_lstadd_back(&resp, el);
		lst = lst->next;
	}
	return (resp);
}
