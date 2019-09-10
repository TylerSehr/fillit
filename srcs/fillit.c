/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:38:16 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 12:06:31 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include <stdlib.h>

int			fillit(char *input_file)
{
	char	**loaded_file;
	int		*output_pieces;
	int		i;

	i = 0;
	output_pieces = (int *)todd(sizeof(int), 26);
	while (i < 26)
	{
		output_pieces[i] = -1;
		i++;
	}
	REQUIRE((loaded_file = load_file(input_file)), 1);
	REQUIRE(validate_input(loaded_file, output_pieces), 2);
	REQUIRE((output_pieces[0] != -1), 3);
	REQUIRE(build_solution(output_pieces), 4);
	return (0);
}

t_bool		validate_input(char **loaded_file, int output_pieces[26])
{
	int status;

	status = run_validation(loaded_file, output_pieces);
	if (status == 0)
		return (TRUE);
	else
		return (FALSE);
}

char		**load_file(char *input_file)
{
	char	**loaded_file;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	loaded_file = (char **)todd(sizeof(char *), 130);
	fd = open(input_file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) == 0)
			line[0] = '\n';
		loaded_file[i] = ft_strdup(line);
		i++;
	}
	loaded_file[i] = ft_strnew(2);
	loaded_file[i][0] = '\n';
	i++;
	loaded_file[i] = (char *)todd(sizeof(char), 1);
	loaded_file[i][0] = '\0';
	return (loaded_file);
}
