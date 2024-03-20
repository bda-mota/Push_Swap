/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 14:48:34 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		(*stack_a) = second;
	}
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		first = (*stack_b);
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		(*stack_b) = second;
	}
}

void	swap_stacks(t_push *push)
{
	if (push->stack_a != NULL && push->stack_b != NULL)
	{
		swap_a(&(push->stack_a));
		swap_b(&(push->stack_b));
	}
}
