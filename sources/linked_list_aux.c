/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:56:11 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 20:38:18 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	get_stack_size(t_stack *stack)
{
	int		count;
	t_stack	*curr;

	count = 0;
	curr = stack;
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

int	get_max(t_stack *stack)
{
	t_stack	*curr;
	int		max;

	curr = stack;
	max = curr->value;
	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}

void remove_first(t_stack **stack) 
{
	t_stack *curr;
	
	if (*stack == NULL)
		return;
	curr = *stack;
	*stack = curr->next;  
	free(curr);
}