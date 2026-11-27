/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsadiki <nsadiki@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:18:02 by nsadiki           #+#    #+#             */
/*   Updated: 2026/11/27 15:06:51 by nsadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_test_err(va_list *ap)
{
	va_end(*ap);
	return (-1);
}

static int	ft_step(const char *format, int *i, va_list *ap)
{
	int	test;

	if (format[*i] == '%')
	{
		if (!format[*i + 1])
			return (handle_test_err(ap));
		test = ft_handler(format[*i + 1], ap);
		if (test == -1)
			return (handle_test_err(ap));
		*i += 2;
		return (test);
	}
	test = ft_putchar(format[*i]);
	if (test == -1)
		return (handle_test_err(ap));
	(*i)++;
	return (test);
}

int	ft_printf(const char *format, ...)
{
	int		total_printed;
	int		test;
	int		i;
	va_list	ap;

	total_printed = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		test = ft_step(format, &i, &ap);
		if (test == -1)
			return (-1);
		total_printed += test;
	}
	va_end(ap);
	return (total_printed);
}
