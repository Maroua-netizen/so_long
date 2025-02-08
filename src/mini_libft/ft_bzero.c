/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:29:35 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 12:40:06 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*pb;

	pb = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		pb[i] = 0;
		i++;
	}
}
