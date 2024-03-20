/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:50:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 14:48:24 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		last = stack_last(*stack_a);
		*stack_a = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		first = (*stack_b);
		last = stack_last(*stack_b);
		*stack_b = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	rotate_stacks(t_push *push)
{
	if (push->stack_a != NULL && push->stack_b != NULL)
	{
		rotate_a(&(push->stack_a));
		rotate_b(&(push->stack_b));
	}
}
