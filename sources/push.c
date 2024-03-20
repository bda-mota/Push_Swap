/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:22 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 14:48:02 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_push *push)
{
	t_stack	*first_b;

	if (push->stack_b != NULL)
	{
		first_b = push->stack_b;
		push->stack_b = first_b->next;
		insert_beginning(&(push->stack_a), first_b);
	}
}

void	push_b(t_push *push)
{
	t_stack	*first_a;

	if (push->stack_a != NULL)
	{
		first_a = push->stack_a;
		push->stack_a = first_a->next;
		insert_beginning(&(push->stack_b), first_a);
	}
}
