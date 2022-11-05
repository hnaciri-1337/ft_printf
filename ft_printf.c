/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:34:44 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/18 14:34:46 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counter(long unsigned int nbr)
{
	int	counter;

	counter = 2;
	while (nbr >= 16)
	{
		counter++;
		nbr /= 16;
	}
	return (counter);
}

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_check_and_print(va_list args, char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putaddress(va_arg(args, long unsigned int)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putlowerbase(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_putupperbase(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = 0;
	total = 0;
	va_start (args, string);
	while (string[i])
	{
		if (string[i] == '%')
			total += ft_check_and_print(args, string[++i]);
		else
			total += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (total);
}
