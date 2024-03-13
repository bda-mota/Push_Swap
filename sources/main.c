/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:45:58 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/13 20:02:31 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	(void)argv;
	return (0);
}