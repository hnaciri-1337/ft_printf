/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:22:45 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/19 19:22:48 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(long int n);
int	ft_counter(long unsigned int nbr);
int	ft_putchar(char c);
int	ft_putstr(char	*str);
int	ft_check_and_print(va_list args, char c);
int	ft_printf(const char *string, ...);
int	ft_putlowerbase(long unsigned int nbr);
int	ft_putupperbase(unsigned int nbr);
int	ft_putaddress(long unsigned int address);

#endif