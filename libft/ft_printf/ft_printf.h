/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:44:03 by mflury            #+#    #+#             */
/*   Updated: 2023/08/07 01:44:03 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putptr(uintptr_t addr);
int	ft_put10(int nbr);
int	ft_putu10(unsigned int nbr);
int	ft_put16(uintptr_t nbr, char *set);

#endif
