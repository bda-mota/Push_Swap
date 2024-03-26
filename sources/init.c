/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:32:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/25 20:29:53 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_list(t_push **stacks)
{
	*stacks = malloc(sizeof(t_push));
	if (*stacks == NULL)
		exit(1);
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
	(*stacks)->size_a = 0;
	(*stacks)->size_b = 0;
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->value = 0;
	(*stack)->index = 0;
	(*stack)->pos = 0;
	(*stack)->target_pos = 0;
	(*stack)->cost_a = 0;
	(*stack)->cost_b = 0;
	(*stack)->next = NULL;
}