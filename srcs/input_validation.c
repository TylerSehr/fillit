/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:10:04 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/09 03:57:39 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

t_bool	run_validation(char **loaded_file, int output_pieces[26])
{
	REQUIRE(check_valid_input_format(loaded_file, 0, 0), 1);
	REQUIRE(check_pieces(loaded_file, output_pieces), 2);
	return (0);
}

t_bool	check_valid_input_format(char **loaded_file, int i, int j)
{
	t_bool	is_valid;

	is_valid = TRUE;
	while (loaded_file[i][0])
	{
		if (ft_strlen(loaded_file[i]) != 4 && ft_strlen(loaded_file[i]) != 1)
			is_valid = FALSE;
		while (loaded_file[i][j] && is_valid)
		{
			if (j > 3)
				is_valid = FALSE;
			if ((i + 1) % 5 > 0)
				if (loaded_file[i][j] != '.' && loaded_file[i][j] != '#')
					is_valid = FALSE;
			if ((i + 1) % 5 == 0)
				if (loaded_file[i][j] != '\n' || j > 0)
					is_valid = FALSE;
			j++;
		}
		j = 0;
		i++;
	}
	return (is_valid);
}

t_bool	check_pieces(char **loaded_file, int output_pieces[26])
{
	int		i;
	int		k;
	char	*piece;
	int		piece_id;

	i = 0;
	k = 0;
	piece = ft_strnew(17);
	while (loaded_file[i][0])
	{
		if ((i + 1) % 5 > 0)
			piece = ft_strcat(piece, loaded_file[i]);
		if ((i + 1) % 5 == 0)
		{
			piece = trim_piece(piece);
			if ((piece_id = is_valid_piece(piece, 0, 0, 0)) == -1)
				return (FALSE);
			output_pieces[k] = piece_id;
			k++;
			ft_bzero(piece, 17);
		}
		i++;
	}
	output_pieces[k] = -1;
	return (TRUE);
}

int		is_valid_piece(char *piece, int i, int j, int count)
{
	const char	*valid_pieces[] = {
		"#...#...#...#", "####", "#...#...##", "###...#",
		"#.###", "##...#...#", "###.#", "#...#..##",
		"#...###", "##..#...#", "##.##", "#...##...#",
		"##...##", "#..##..#", "##..##", "#..###",
		"#...##..#", "###..#", "#..##...#"};

	while (piece[j])
	{
		if (piece[j] == '#')
			count++;
		j++;
	}
	if (count != 4)
		return (-1);
	while (i < 19)
	{
		if (ft_strncmp(piece, valid_pieces[i], ft_strlen(valid_pieces[i])) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*trim_piece(char const *s)
{
	char	*trimmed_string;

	trimmed_string = ft_strnew(ft_strlen(s));
	while (*s && *s != '#')
		s++;
	trimmed_string = ft_strcpy(trimmed_string, s);
	return (trimmed_string);
}
