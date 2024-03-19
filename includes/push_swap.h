/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:24 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/19 14:42:05 by bda-mota         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

typedef struct push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
} t_push;


//UTILS
void	exit_error(void);
void	print_list(t_stack **stack);

//LINKED_LIST
void	insert_beginning(t_stack **stack, t_stack *new);
void	insert_end(t_stack **stack, int value);
void	deallocate(t_stack **stack);
void	has_double(t_push *push_swap);
void	free_lists(t_push *push_swap);
int		is_ordered(t_stack *stack);
t_stack	*stack_last(t_stack *lst);

//SWAP
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_stacks(t_push *push_swap);

//PUSH
void	push_a(t_push *push_swap);
void	push_b(t_push *push_swap);

//ROTATE 
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_stacks(t_push *push_swap);

//REVERSE ROTATE
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_stacks(t_push *push_swap);

#endif
