/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:03:12 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 16:56:22 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putptr(unsigned long long ptr, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (ptr >= 16)
		ft_putptr(ptr / 16, count);
	write(1, &hexa[ptr % 16], 1);
	(*count)++;
}
