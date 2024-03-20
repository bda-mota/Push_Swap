/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:50:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 15:54:30 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = (*stack);
		last = stack_last(*stack);
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ra(t_push *push)
{
	rotate(&push->stack_a);
}

void	rb(t_push *push)
{
	rotate(&push->stack_b);
}


void	rr(t_push *push)
{
	if (push->stack_a != NULL)
		rotate(&(push->stack_a));
	if (push->stack_b != NULL)
		rotate(&(push->stack_b));
}
