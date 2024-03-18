/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:22 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/18 17:51:54 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_push *push_swap)
{
	t_stack	*first_a;
	
	if (push_swap->stack_a != NULL)
	{
		first_a = push_swap->stack_a;
		push_swap->stack_a = first_a->next;
		insert_beginning(&(push_swap->stack_b), first_a);
	}
}