/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:04:31 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/13 12:47:39 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "todd.h"

void	*todd(size_t size, int multiplier)
{
	void *maximum_todd;

	maximum_todd = malloc(size * multiplier + 1);
	if (g_od_todd != NULL)
		increase_todd(maximum_todd);
	return (maximum_todd);
}

void	increase_todd(void *todds_mobile_data)
{
	while (g_od_todd->next)
		g_od_todd = g_od_todd->next;
	g_od_todd->variable = todds_mobile_data;
	g_od_todd->next = (t_todd_store_clerk *)malloc(sizeof(t_todd_store_clerk));
	g_od_todd->next->start = g_od_todd->start;
	g_od_todd = g_od_todd->next;
	g_od_todd->next = NULL;
}

void	build_a_todd(void)
{
	g_od_todd = (t_todd_store_clerk *)malloc(sizeof(t_todd_store_clerk));
	g_od_todd->variable = NULL;
	g_od_todd->next = NULL;
	g_od_todd->start = g_od_todd;
}

void	and_so_ends_the_reign_of_todd(void)
{
	int					debug;
	t_todd_store_clerk	*temporary_todd;

	debug = 1;
	g_od_todd = g_od_todd->start;
	while (g_od_todd->next && debug)
	{
		if (g_od_todd->variable)
		{
			free(g_od_todd->variable);
		}
		temporary_todd = g_od_todd;
		g_od_todd = g_od_todd->next;
		if (temporary_todd)
		{
			free(temporary_todd);
		}
	}
}

void	todd_kosher_free(void *todd_target)
{
	free(todd_target);
	todd_target = NULL;
}