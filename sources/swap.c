/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 20:14:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = (*stack);
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		(*stack) = second;
	}
}

void	sa(t_push *stacks)
{
	swap(&stacks->stack_a);
	ft_printf("sa\n");
}

void	sb(t_push *stacks)
{
	swap(&stacks->stack_b);
	ft_printf("sb\n");
}

void	ss(t_push *stacks)
{
	if (stacks->stack_a != NULL)
		swap(&(stacks->stack_a));
	if (stacks->stack_b != NULL)
		swap(&(stacks->stack_b));
	ft_printf("ss\n");
}
