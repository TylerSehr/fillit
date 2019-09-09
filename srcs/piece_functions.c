/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:22:43 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/09 03:51:31 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

void	delete_piece(t_board *board, int index)
{
	board = board->start;
	while (board)
	{
		if (board->value == ('A' + index))
			board->value = '.';
		board = board->next;
	}
}

t_bool	place_point(t_board *board, int piece_i, int i, int index)
{
	t_board	*start;

	start = board;
	while (board)
	{
		if (board->y == start->y + g_offsets[piece_i][i - 1]
		&& board->x == start->x + g_offsets[piece_i][i]
		&& board->value == '.')
		{
			board->value = 'A' + index;
			return (TRUE);
		}
		board = board->next;
	}
	return (FALSE);
}

t_bool	place_piece(t_board *board, int piece_index, int index)
{
	int i;

	i = 1;
	while (i < 9)
	{
		if (place_point(board, piece_index, i, index) == FALSE)
		{
			delete_piece(board, index);
			return (FALSE);
		}
		i += 2;
	}
	return (TRUE);
}
