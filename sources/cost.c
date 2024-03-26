/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:31:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/26 11:49:08 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_abs(int a, int b);

void	calculate_costs(t_push **stacks)
{
	calc_cost_a((*stacks)->stack_a);
	calc_cost_b((*stacks)->stack_b);
}

void	calc_cost_a(t_stack *stack_a)
{
	t_stack	*curr;
	int		media;
	int		size;

	size = get_stack_size(stack_a);
	media = size / 2;
	curr = stack_a;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_a = curr->pos;
		else
			curr->cost_a = (size - curr->pos) * -1;
		curr = curr->next;
	}
}

void	calc_cost_b(t_stack *stack_b)
{
	t_stack	*curr;
	int		media;
	int		size;

	size = get_stack_size(stack_b);
	media = size / 2;
	curr = stack_b;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_b = curr->pos + 1;
		else
			curr->cost_b = (size - curr->pos + 1) * -1;
		curr = curr->next;
	}
}

void	total_cost(t_push **stacks)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	
	curr_a = (*stacks)->stack_a;
	while (curr_a)
	{
		curr_b = (*stacks)->stack_b;
		while (curr_b)
		{
			if (curr_b->target_pos == curr_a->pos)
				curr_b->cost = get_abs(curr_a->cost_a, curr_b->cost_b);
			curr_b = curr_b->next;
		}
		curr_a = curr_a->next;
	}	
}

static int	get_abs(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}