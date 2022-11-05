/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:26:40 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/19 19:26:42 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlowerbase(long unsigned int nbr)
{
	char	*p;
	char	*array;
	int		i;
	int		len;

	p = malloc (sizeof(char) * ft_counter(nbr));
	array = malloc (sizeof(char) * 17);
	i = -1;
	while (++i < 10)
		array[i] = i + 48;
	i--;
	while (++i < 16)
		array[i] = i + 87;
	array[i] = '\0';
	i = ft_counter(nbr) - 1;
	p[i] = '\0';
	while (--i >= 0)
	{
		p[i] = array[nbr % 16];
		nbr /= 16;
	}
	len = ft_putstr(p);
	free (p);
	free (array);
	return (len);
}

int	ft_putupperbase(unsigned int nbr)
{
	char	*p;
	char	*array;
	int		i;
	int		len;

	i = -1;
	p = malloc (sizeof(char) * ft_counter(nbr));
	array = malloc (sizeof(char) * 17);
	while (++i < 10)
		array[i] = i + 48;
	i--;
	while (++i < 16)
		array[i] = i + 55;
	array[i] = '\0';
	i = ft_counter(nbr) - 1;
	p[i] = '\0';
	while (--i >= 0)
	{
		p[i] = array[nbr % 16];
		nbr /= 16;
	}
	len = ft_putstr(p);
	free (p);
	free (array);
	return (len);
}

int	ft_putaddress(long unsigned int address)
{
	int	len;

	len = ft_putstr("0x");
	len += ft_putlowerbase(address);
	return (len);
}
