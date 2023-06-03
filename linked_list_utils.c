/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 02:54:31 by mflury            #+#    #+#             */
/*   Updated: 2023/06/03 02:54:31 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = malloc( 1 * sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int i = 0;

	a = ft_lstnew(i++);
	while (i <= 10)
		ft_lstadd_front(&a, ft_lstnew(i++));
	while (a->next)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}
