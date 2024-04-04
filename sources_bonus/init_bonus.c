/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:32:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 15:44:39 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	init_list(t_push **stacks)
{
	*stacks = malloc(sizeof(t_push));
	if (*stacks == NULL)
		exit(1);
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
}

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->value = 0;
	(*stack)->next = NULL;
}
