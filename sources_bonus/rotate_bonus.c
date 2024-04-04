/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:50:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 15:15:39 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

void	ra(t_push *stacks)
{
	rotate(&stacks->stack_a);
	ft_printf("ra\n");
}

void	rb(t_push *stacks)
{
	rotate(&stacks->stack_b);
	ft_printf("rb\n");
}

void	rr(t_push *stacks)
{
	if (stacks->stack_a != NULL)
		rotate(&(stacks->stack_a));
	if (stacks->stack_b != NULL)
		rotate(&(stacks->stack_b));
	ft_printf("rr\n");
}
