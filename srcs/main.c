/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:27:09 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 10:26:50 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	debug;
	int status;

	build_a_todd();
	status = 0;
	debug = 1;
	if (argc != 2)
		ft_putstr("usage: cp target_file\n");
	else
		status = fillit(argv[1]);
	if (status != 0)
		ft_putstr("error\n");
	if (debug)
		system("leaks fillit");
	return (0);
}
