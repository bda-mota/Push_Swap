/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_hex_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:12:50 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 18:41:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_lower_hex(unsigned int n)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (n < 16)
		count += write(1, &hex[n], 1);
	else
	{
		count += ft_p_lower_hex(n / 16);
		count += ft_p_lower_hex(n % 16);
	}
	return (count);
}

int	ft_p_upper_hex(unsigned int n)
{
	int		count;
	char	*hex;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += write(1, &hex[n], 1);
	else
	{
		count += ft_p_upper_hex(n / 16);
		count += ft_p_upper_hex(n % 16);
	}
	return (count);
}

static int	ft_aux_address(unsigned long p)
{
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (p < 16)
		count += write(1, &hex[p], 1);
	else
	{
		count += ft_aux_address(p / 16);
		count += ft_aux_address(p % 16);
	}
	return (count);
}

int	ft_p_address(unsigned long p)
{
	if (p == 0)
		return (write(1, "(nil)", 5));
	return ((write(1, "0x", 2)) + (ft_aux_address(p)));
}
