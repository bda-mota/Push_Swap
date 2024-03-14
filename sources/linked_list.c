/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 17:11:35 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_end(t_stack **stack, int value)
{
	t_stack	*curr;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	print_list(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
}
