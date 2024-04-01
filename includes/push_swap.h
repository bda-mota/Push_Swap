/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:24 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/01 19:33:12 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				cost;
	struct s_stack	*next;
}	t_stack;

typedef struct push
{
	int		max_value;
	int		min_value;
	int		media;
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_push;

//INIT
void	init_list(t_push **stacks);
void	init_stack(t_stack **stack);

//PUSH SWAP
void	sort_three(t_push **push);
void	push_swap(t_push **push);
void	sort_many(t_push **push);
void	do_op(t_push **stacks);

//UTILS
void	exit_error(void);
void	print_list(t_stack **stack);
int		get_abs(int a, int b);

//LINKED_LIST
void	insert_beginning(t_stack **stack, t_stack *new);
void	insert_end(t_stack **stack, int value);
void	deallocate(t_stack **stack);
void	free_lists(t_push *push);
t_stack	*stack_last(t_stack *lst);

//LINKED LIST AUX 
void	has_double(t_push *push);
int		is_ordered(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		get_max(t_stack *stack);
void	remove_first(t_stack **stack);

//SWAP
void	swap(t_stack **stack);
void	sa(t_push *push);
void	sb(t_push *push);
void	ss(t_push *push);

//PUSH
void	pa(t_push *push);
void	pb(t_push *push);

//ROTATE
void	rotate(t_stack **stack);
void	ra(t_push *push);
void	rb(t_push *push);
void	rr(t_push *push);

//REVERSE ROTATE
void	reverse_rotate(t_stack **stack);
void	rrr(t_push *push);
void	rra(t_push *push);
void	rrb(t_push *push);

//INDEX AND POSITION
void	media_and_push(t_push **stacks);
void	put_index(t_push **stacks);
int		calculate_media_index(t_stack *stack);
void	find_position(t_push **stacks);
void	find_target_pos(t_push **stacks);

//COST
void	calculate_costs(t_push **stacks);
void	calc_cost_a(t_stack *stack_a);
void	calc_cost_b(t_stack *stack_b);
void	total_cost(t_push **stacks);
int		find_cheaper(t_stack *stack_b);

//OPERATIONS
void	find_op(t_push **stacks);
void	move_a(t_push **stacks, int pos);
void	move_b(t_push **stacks, int pos);
void	moves(t_push **stacks, int target_pos, int pos_b);

//UPDATE
void	update_rrr(t_push **stacks);
void	update_rr(t_push **stacks);
int		find_index_cheaper(t_stack *stack_b, int value);

#endif
