/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:39:36 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/21 16:23:29 by bda-mota         ###   ########.fr       */
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

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->value = 8;
	(*stack)->index = 0;
	(*stack)->pos = 0;
	(*stack)->target_pos = 0;
	(*stack)->cost_a = 0;
	(*stack)->cost_b = 0;
	(*stack)->next = NULL;
}
