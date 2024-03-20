/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:55:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 15:23:57 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_push **push)
{
	//sort_three(&push);
}

void	get_size(t_push *push)
{
	push->size_a = get_stack_size(push->stack_a);
	push->size_b = get_stack_size(push->stack_b);
}

// void	sort_three(t_push **push)
// {

// }
