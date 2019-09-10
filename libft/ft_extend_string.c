/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:01:57 by tsehr             #+#    #+#             */
/*   Updated: 2019/09/10 10:49:49 by tsehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_extend_string(char *src, size_t size)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
		size++;
	}
	i = 0;
	temp = ft_strnew(size);
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
