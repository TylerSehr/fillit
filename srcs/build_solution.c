/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:39:51 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 09:50:15 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

t_bool	build_solution(int output_pieces[26])
{
	int status;

	status = calculate_solution(output_pieces);
	if (status == 0)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	calculate_solution(int output_pieces[26])
{
	t_board	*board;
	int		board_offset;

	board_offset = 0;
	board = (t_board *)todd(sizeof(t_board), 1);
	board->x = 0;
	board->y = 0;
	board->value = '.';
	board->next = NULL;
	board->start = board;
	build_board(output_pieces, board, board_offset);
	REQUIRE(board->next, 1);
	while (!b(board, output_pieces, 0))
	{
		clear_board(board);
		board_offset++;
		build_board(output_pieces, board, board_offset);
	}
	return (0);
}

t_bool	b(t_board *board, int pieces[26], int piece_index)
{
	board = board->start;
	if (pieces[piece_index] == -1)
	{
		print_board(board);
		return (TRUE);
	}
	while (board)
	{
		if (place_piece(board, pieces[piece_index], piece_index))
		{
			if (b(board, pieces, piece_index + 1))
				return (TRUE);
			delete_piece(board, piece_index + 1);
		}
		board = board->next;
	}
	return (FALSE);
}
