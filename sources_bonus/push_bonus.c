/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:22 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 16:19:51 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	pa(t_push *stacks)
{
	t_stack	*first_b;

	if (stacks->stack_b != NULL)
	{
		first_b = stacks->stack_b;
		stacks->stack_b = first_b->next;
		insert_beginning(&(stacks->stack_a), first_b);
	}
}

void	pb(t_push *stacks)
{
	t_stack	*first_a;

	if (stacks->stack_a != NULL)
	{
		first_a = stacks->stack_a;
		stacks->stack_a = first_a->next;
		insert_beginning(&(stacks->stack_b), first_a);
	}
}
