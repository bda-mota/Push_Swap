/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_aux_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:56:11 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 15:53:23 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	has_double(t_push *stacks)
{
	t_stack	*curr;
	t_stack	*runner;

	curr = stacks->stack_a;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value == runner->value)
			{
				free_lists(stacks);
				exit_error();
			}
			runner = runner->next;
		}
		curr = curr->next;
	}
}

int	is_ordered(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	remove_first(t_stack **stack)
{
	t_stack	*curr;

	if (*stack == NULL)
		return ;
	curr = *stack;
	*stack = curr->next;
	free(curr);
}
