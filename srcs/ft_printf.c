/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:47:37 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/09 15:47:35 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_parse(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = putnbr(va_arg(args, int));
	if (c == 'c')
		count = putchar2(va_arg(args, int));
	if (c == 's')
		count = put_str(va_arg(args, char *));
	if (c == 'p')
		count = put_pt(va_arg(args, long unsigned), "0123456789abcdef");
	if (c == 'u')
		count = put_unsignednbr(va_arg(args, unsigned int));
	if (c == 'x')
		count = put_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count = put_hexa(va_arg(args, int), "0123456789ABCDEF");
	if (c == '%')
		count = putchar2('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count += ft_parse(str[++i], args);
		else
		{
			putchar2(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
//----------------------------------------------
/*#include <stdio.h>

int	main()
{
	char	*str = " %x ";
	int	result1;
	int result2;

	result1 = printf(str, 0);
	printf("\n");
	result2 = ft_printf(str, 0);
	printf("\nresult_ordi : %d\n",result1);
	printf("result_moi : %d\n",result2);
	return (0);
}*/
