/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:55:24 by mfakih            #+#    #+#             */
/*   Updated: 2025/11/16 10:17:31 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(char c, int fd, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_len(va_arg(list, int), fd);
	else if (c == 's')
		count = ft_putstr_len(va_arg(list, char *), fd);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_len(va_arg(list, int), fd);
	else if (c == 'u')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789", fd);
	else if (c == 'x')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789abcdef", fd);
	else if (c == 'X')
		count = ft_putnbr_base_len(va_arg(list, unsigned int),
				"0123456789ABCDEF", fd);
	else if (c == 'p')
		count = ft_putptr_len(va_arg(list, void *), fd);
	else if (c == '%')
		count = ft_putchar_len('%', fd);
	return (count);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar_len(s[i], fd);
			count++;
		}
		else
		{
			i++;
			if (s[i])
				count += type(s[i], fd, list);
		}
		i++;
	}
	va_end(list);
	return (count);
}
