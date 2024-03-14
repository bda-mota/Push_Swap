/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:46:24 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 17:17:11 by bda-mota         ###   ########.fr       */
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

//UTILS
void	exit_error(void);

//LINKED_LIST
void	insert_end(t_stack **stack, int value);
void	print_list(t_stack **stack);

#endif
