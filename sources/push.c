/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:22 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 20:13:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_push *stacks)
{
	t_stack	*first_b;

	if (stacks->stack_b != NULL)
	{
		first_b = stacks->stack_b;
		stacks->stack_b = first_b->next;
		insert_beginning(&(stacks->stack_a), first_b);
		ft_printf("pa\n");
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
		ft_printf("pb\n");
	}
}
