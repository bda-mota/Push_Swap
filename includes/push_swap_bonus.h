/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:24 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 15:46:55 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/src/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push;

//INIT BONUS
void	init_list(t_push **stacks);
void	init_stack(t_stack **stack);

//PUSH SWAP BONUS
void	sort_three(t_push **push);
void	push_swap(t_push **push);
void	sort_many(t_push **push);
void	do_op(t_push **stacks);

//UTILS BONUS
void	exit_error(void);

//LINKED_LIST BONUS
void	insert_beginning(t_stack **stack, t_stack *new);
void	insert_end(t_stack **stack, int value);
void	deallocate(t_stack **stack);
void	free_lists(t_push *push);
t_stack	*stack_last(t_stack *lst);

//LINKED LIST AUX  BONUS
void	has_double(t_push *push);
int		is_ordered(t_stack *stack);
void	remove_first(t_stack **stack);

//SWAP BONUS
void	swap(t_stack **stack);
void	sa(t_push *push);
void	sb(t_push *push);
void	ss(t_push *push);

//PUSH BONUS
void	pa(t_push *push);
void	pb(t_push *push);

//ROTATE BONUS
void	rotate(t_stack **stack);
void	ra(t_push *push);
void	rb(t_push *push);
void	rr(t_push *push);

//REVERSE ROTATE BONUS
void	reverse_rotate(t_stack **stack);
void	rrr(t_push *push);
void	rra(t_push *push);
void	rrb(t_push *push);

#endif
