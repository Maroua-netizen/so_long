/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:21:25 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/08 17:01:48 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned int n, int i, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putptr(unsigned long long ptr, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putunbr(unsigned int n, int *count);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_printf(const char *format, ...);
void	my_mlx_pixel_put(t_data *img_ptr, int x, int y, int color);
char	*get_next_line(int fd);
char	**get_map(char *file_name);
void	free_map(char **map);
int		map_line_count(char *file_name);
int		check_map(char *file_name);
int		collectibles_count(char **map);
int		flood_check(char *file_name);

#endif