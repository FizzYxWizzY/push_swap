/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:35:49 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:35:49 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	i;
	size_t	j;

	if (find[0] == 0)
		return ((char *)s);
	i = 0;
	j = 0;
	while (i < slen && s[i])
	{
		while (s[i + j] == find[j] && s[i + j] && (i + j) < slen)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)s + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
