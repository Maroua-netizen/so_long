/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:23:39 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 12:40:19 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[ft_strlen(s1)] = '\0';
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
