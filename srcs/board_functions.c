/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:58:44 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 09:50:10 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	initialize_board(t_board *board, int x, int y)
{
	board->x = x;
	board->y = y;
	board->value = '.';
	board->next = NULL;
}

void	build_board(int pieces[26], t_board *board, int offset)
{
	int		side_length;
	int		total_length;
	int		y;
	int		x;
	t_board	*start;

	x = 1;
	y = 0;
	side_length = square_root(arraylen(pieces) * 4) + offset;
	total_length = side_length * side_length - 1;
	while (total_length > 0)
	{
		if (total_length % side_length == 0)
		{
			y++;
			x = 0;
		}
		start = board->start;
		board->next = (t_board *)todd(sizeof(t_board), 1);
		board = board->next;
		initialize_board(board, x, y);
		board->start = start;
		x++;
		total_length--;
	}
}

void	clear_board(t_board *board)
{
	board = board->start;
	while (board)
	{
		board->value = '.';
		board = board->next;
	}
}
