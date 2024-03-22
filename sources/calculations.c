/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:43:01 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/22 12:56:19 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calculate_index(t_stack *stack);

void	put_index(t_push **stacks)
{
	t_stack	*curr;
	t_stack	*runner;
	int		index;

	curr = (*stacks)->stack_a;
	while (curr)
	{
		index = 1;
		runner = (*stacks)->stack_a;
		while (runner)
		{
			if (runner->value < curr->value)
				index++;
			runner = runner->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

static int	calculate_index(t_stack *stack)
{
	int	result;
	
	result = 0;
	while (stack)
	{
		result += stack->index;
		stack = stack->next;
	}
	return (result);
}

void	media_and_push(t_push **stacks)
{
	t_stack	*curr;
	int		media;
	int		size;
	int		result;

	curr = (*stacks)->stack_a;
	size = get_stack_size((*stacks)->stack_a);
	while (size > 3)
	{
		size = get_stack_size((*stacks)->stack_a);
		if (size == 3)
			break ;
		result = calculate_index((*stacks)->stack_a);
		media = result / size;
		curr = (*stacks)->stack_a;
		if (curr->index <= media)
			pb(*stacks);
		else
		ra(*stacks);
	}
}