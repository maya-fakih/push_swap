/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:18:19 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/01 21:18:30 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putfloat_len(double f, int fd)
{
	long	nb;
	int		count;

	count = 0;
	if (f < 0)
	{
		count += ft_putchar_len('-', fd);
		f = -f;
	}
	nb = (long)(f * 100);
	if (nb >= 100)
		count += ft_putnbr_base_len(nb / 100, "0123456789", fd);
	else
		count += ft_putchar_len('0', fd);
	count += ft_putchar_len('.', fd);
	if (nb % 100 < 10)
		count += ft_putchar_len('0', fd);
	count += ft_putnbr_base_len(nb % 100, "0123456789", fd);
	return (count);
}
