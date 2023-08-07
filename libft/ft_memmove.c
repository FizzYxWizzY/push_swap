/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:58:47 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:58:47 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pt_src;
	char	*pt_dst;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	if ((pt_src == NULL) && (pt_dst == NULL))
		return (NULL);
	if ((pt_src < pt_dst) && (pt_dst < pt_src + n))
	{
		pt_dst += n;
		pt_src += n;
		while (n)
		{
			*--pt_dst = *--pt_src;
			n--;
		}
	}
	else
	{
		while (n--)
			*pt_dst++ = *pt_src++;
	}
	return (dst);
}
