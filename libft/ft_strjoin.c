/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:10:58 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:10:58 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resp;
	size_t	i;

	resp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		resp[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		resp[i] = *s2;
		i++;
		s2++;
	}
	resp[i] = '\0';
	return (resp);
}
