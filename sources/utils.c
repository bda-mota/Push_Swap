/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:39:36 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/26 12:13:37 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	print_list(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
}

int	get_abs(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}