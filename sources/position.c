/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:53 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/03 14:57:01 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_position(t_push **stacks)
{
	t_stack	*curr;
	int		position;

	position = 0;
	curr = (*stacks)->stack_a;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}
	position = 0;
	curr = (*stacks)->stack_b;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}
}

void	find_target_pos(t_push **stacks)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_b = (*stacks)->stack_b;
	while (curr_b)
	{
		curr_b->target_pos = MAX_INT;
		curr_a = (*stacks)->stack_a;
		while (curr_a)
		{
			if (curr_b->index < curr_a->index
				&& (curr_a->index < curr_b->target_pos || !curr_b->target_pos))
			{
				curr_b->target_pos = curr_a->index;
			}
			curr_a = curr_a->next;
		}
		curr_b = curr_b->next;
	}
}

int	get_min_position(t_stack *stack_a)
{
	t_stack	*curr;
	int		min_index;
	int		min_pos;

	curr = stack_a;
	min_index = MAX_INT;
	min_pos = curr->pos;
	while (curr)
	{
		if (curr->index < min_index)
		{
			min_index = curr->index;
			min_pos = curr->pos;
		}
		curr = curr->next;
	}
	return (min_pos);
}
