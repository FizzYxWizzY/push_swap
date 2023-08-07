/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:04:25 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:04:25 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_free_all(char **arr);
static unsigned int	count_strs(char const *s, char c);
static void			init_el(char **str, unsigned int *str_len, char c);

char	**ft_split(char const *s, char c)
{
	char			**resp;
	char			*str;
	unsigned int	i;
	unsigned int	nbr_strs;
	unsigned int	str_len;

	nbr_strs = count_strs(s, c);
	resp = malloc(sizeof(char *) * (nbr_strs + 1));
	if (!resp)
		return (NULL);
	str = (char *)s;
	str_len = 0;
	i = 0;
	while (i < nbr_strs)
	{
		init_el(&str, &str_len, c);
		resp[i] = malloc(sizeof(char) * (str_len + 1));
		if (resp[i] == NULL)
			return (ft_free_all(resp));
		ft_strlcpy(resp[i], str, str_len + 1);
		i++;
	}
	resp[i] = NULL;
	return (resp);
}

static char	**ft_free_all(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static unsigned int	count_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	resp;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	resp = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			resp++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		resp++;
	return (resp);
}

static void	init_el(char **str, unsigned int *str_len, char c)
{
	unsigned int	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}
