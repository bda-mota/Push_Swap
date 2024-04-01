/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:18:13 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/01 19:21:27 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_rrr(t_push **stacks)
{
	rrr(*stacks);
	(*stacks)->stack_a->cost_a++;
	(*stacks)->stack_b->cost_b++;
}

void	update_rr(t_push **stacks)
{
	rr(*stacks);
	(*stacks)->stack_a->cost_a--;
	(*stacks)->stack_b->cost_b--;
}