/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:31:32 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/09 15:48:25 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(int nb)
{
	long		n;
	static int	count;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count = putchar2('-');
		n = -n;
	}
	if (n >= 10)
	{
		count = count + putnbr(n / 10);
		count = count + putnbr(n % 10);
	}
	else
	{
		count = count + putchar2(n + '0');
	}
	return (count);
}

int	put_unsignednbr(unsigned int nb)
{
	unsigned long	n;
	static int		count;

	n = nb;
	count = 0;
	if (n >= 10)
	{
		count = count + putnbr(n / 10);
		count = count + putnbr(n % 10);
	}
	else
		count = count + putchar2(n + '0');
	return (count);
}

int	put_str(char *str)
{
	int	i;

	if (!str)
		return (put_str("(null)"));
	i = 0;
	while (str[i])
	{
		putchar2(str[i]);
		i++;
	}
	return (i);
}

int	put_hexa(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	count;

	if (nbr == 0)
		return (putchar2('0'));
	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	count = i;
	while (--i >= 0)
		putchar2(base[nbr_final[i]]);
	return (count);
}

int	put_pt(long unsigned nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	count;

	if (!nbr)
		return (put_str("0x0"));
	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	count = i;
	putchar2('0');
	putchar2('x');
	while (--i >= 0)
		putchar2(base[nbr_final[i]]);
	return (count + 2);
}
