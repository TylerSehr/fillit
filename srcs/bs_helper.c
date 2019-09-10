/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:58:47 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 09:35:30 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_board *board)
{
	board = board->start;
	while (board)
	{
		ft_putchar(board->value);
		if (!board->next)
			break ;
		if (board->next->x == 0)
			ft_putchar('\n');
		board = board->next;
	}
	ft_putchar('\n');
}

int		square_root(int num)
{
	int i;

	i = 0;
	while (i * i < num)
		i++;
	return (i);
}

int		arraylen(int *array)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	return (i);
}
