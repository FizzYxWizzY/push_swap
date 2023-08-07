/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:46:46 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 00:46:46 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n);

char	*ft_itoa(int n)
{
	int		nbr_digit;
	char	*str;
	long	nbr;
	int		i;

	nbr = n;
	nbr_digit = count_digit(nbr);
	str = malloc(sizeof(char) * (nbr_digit + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	if (nbr < 0)
		nbr = -nbr;
	i = nbr_digit - 1;
	while (nbr != 0)
	{
		str[i] = 48 + nbr % 10;
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[nbr_digit] = '\0';
	return (str);
}

static int	count_digit(long n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	if (n == 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}
