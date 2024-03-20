/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:12:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 14:48:16 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		prev = NULL;
		last = (*stack_a);
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		prev = NULL;
		last = (*stack_b);
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
}

void	reverse_rotate_stacks(t_push *push)
{
	if (push->stack_a != NULL && push->stack_b != NULL)
	{
		reverse_rotate_a(&(push->stack_a));
		reverse_rotate_b(&(push->stack_b));
	}
}
