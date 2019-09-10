/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:04:34 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 10:19:44 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODD_H
# define TODD_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_toddin
{
	void			*variable;
	struct s_toddin	*next;
	struct s_toddin	*start;
}					t_todd_store_clerk;

t_todd_store_clerk	*g_od_todd;

void				*todd(size_t size, int multiplier);
void				increase_todd(void *todds_mobile_data);
void				build_a_todd();
void				and_so_ends_the_reign_of_todd();

#endif
