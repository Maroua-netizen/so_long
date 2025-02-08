/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:03:12 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 16:53:10 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_puthex(unsigned int n, int i, int *count)
{
	char	*hexa0;
	char	*hexa1;

	hexa0 = "0123456789abcdef";
	hexa1 = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthex(n / 16, i, count);
	if (i == 0)
		write(1, &hexa0[n % 16], 1);
	else if (i == 1)
		write(1, &hexa1[n % 16], 1);
	(*count)++;
}
