/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:31:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/25 21:22:38 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_costs(t_push **stacks)
{
	calc_cost_a((*stacks)->stack_a);
	calc_cost_b((*stacks)->stack_b);
}

void	calc_cost_a(t_stack *stack_a)
{
	t_stack	*curr;
	int		media;

	media = get_stack_size(stack_a) / 2;
	curr = stack_a;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_a = curr->pos;
		else
			curr->cost_a = (curr->pos - media) * -1;
		curr = curr->next;
	}
}

void	calc_cost_b(t_stack *stack_b)
{
	t_stack	*curr;
	int		media;

	media = get_stack_size(stack_b) / 2;
	curr = stack_b;
	while (curr)
	{
		if (curr->pos <= media)
			curr->cost_b = curr->pos + 1;
		else
			curr->cost_b = (curr->pos - media + 1) * -1;
		curr = curr->next;
	}
}

int	get_absolute(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}