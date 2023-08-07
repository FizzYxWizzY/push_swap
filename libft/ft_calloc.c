/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:37:53 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:37:53 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*resp;

	if (!nmemb || !size)
		return (malloc(0));
	resp = malloc(nmemb * size);
	if (!resp)
		return (NULL);
	ft_memset((unsigned char *)resp, 0, nmemb * size);
	return (resp);
}
