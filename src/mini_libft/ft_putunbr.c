/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:03:12 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 16:57:51 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putunbr(n / 10, count);
	n = n % 10 + '0';
	write(1, &n, 1);
	(*count)++;
}
