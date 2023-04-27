/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:56:15 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/09 15:16:11 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	putnbr(int nb);
int	put_unsignednbr(unsigned int nb);
int	put_str(char *str);
int	put_hexa(unsigned int nbr, char *base);
int	put_pt(long unsigned nbr, char *base);
int	putchar2(char c);
int	ft_parse(char c, va_list args);
int	ft_printf(const char *str, ...);
#endif
