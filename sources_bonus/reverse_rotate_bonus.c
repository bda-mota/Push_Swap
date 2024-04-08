/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:12:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/08 12:29:59 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

void	rra(t_push *stacks)
{
	reverse_rotate(&stacks->stack_a);
}

void	rrb(t_push *stacks)
{
	reverse_rotate(&stacks->stack_b);
}

void	rrr(t_push *stacks)
{
	if (stacks->stack_a != NULL)
		reverse_rotate(&stacks->stack_a);
	if (stacks->stack_b != NULL)
		reverse_rotate(&stacks->stack_b);
}
