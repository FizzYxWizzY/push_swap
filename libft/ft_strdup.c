/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:07:33 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:07:33 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*resp;

	size = ft_strlen(s);
	resp = (char *)malloc(sizeof(char) * (size + 1));
	if (resp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(resp + i) = *(char *)(s + i);
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
