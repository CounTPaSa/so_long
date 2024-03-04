/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merboyac <muheren2004@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:17:06 by merboyac          #+#    #+#             */
/*   Updated: 2023/11/24 12:03:59 by merboyac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE10
#  define BASE10 "0123456789"
# endif

# ifndef BASE16LOWER
#  define BASE16LOWER "0123456789abcdef"
# endif

# ifndef BASE16UPPER
#  define BASE16UPPER "0123456789ABCDEF"
# endif

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long int nbr);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_point(unsigned long int p, int check);

#endif
