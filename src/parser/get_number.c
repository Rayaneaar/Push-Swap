/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaribou <raaribou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 15:37:46 by raaribou          #+#    #+#             */
/*   Updated: 2026/11/26 22:05:06 by raaribou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(char c, int *pos, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign *= -1;
		(*pos)++;
	}
}

int	get_number(char *str, int *j, int *success)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	check_sign(str[*j], j, &sign);
	if (!str[*j])
		return (handle_error(success));
	while (str[*j] && ft_isdigit(str[*j]))
	{
		if (result > (LONG_MAX - (str[*j] - '0')) / 10)
			return (handle_error(success));
		result = result * 10 + (str[*j] - '0');
		(*j)++;
	}
	if (str[*j] && !ft_isspace(str[*j]))
		return (handle_error(success));
	result *= sign;
	if (validate_number(result) == -1)
		return (handle_error(success));
	return (result);
}
