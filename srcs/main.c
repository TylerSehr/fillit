/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:27:09 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/09 03:47:44 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int status;

	status = 0;
	if (argc != 2)
		ft_putstr("usage: cp target_file\n");
	else
		status = fillit(argv[1]);
	if (status != 0)
		ft_putstr("error");
	return (0);
}
