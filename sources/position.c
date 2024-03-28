/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:53 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 16:54:00 by bda-mota         ###   ########.fr       */
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
	int		last_value;

	curr_b = (*stacks)->stack_b;
	while (curr_b)
	{
		curr_a = (*stacks)->stack_a;
		last_value = curr_a->pos;
		while (curr_a)
		{
			if (curr_b->index < curr_a->index)
			{
				curr_b->target_pos = curr_a->pos;
			}
			curr_a = curr_a->next;
		}
		curr_b = curr_b->next;	
	}
}

int	find_minor(t_stack *stack, int last_value)
{
	t_stack	*curr;
	int		minor;

	minor = -1;
    while (curr) 
	{
        if (curr->index > last_value && (minor == -1 || curr->index < minor))
            minor = curr->index;
        curr = curr->next;
    }
    return (minor);
}