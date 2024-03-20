/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:12:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 15:54:40 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		prev = NULL;
		last = (*stack);
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_push *push)
{
	reverse_rotate(&push->stack_a);
}

void	rrb(t_push *push)
{
	reverse_rotate(&push->stack_b);
}

void	rrr(t_push *push)
{
	if (push->stack_a != NULL)
		reverse_rotate(&push->stack_a);
	if (push->stack_b != NULL)
		reverse_rotate(&push->stack_b);
}
