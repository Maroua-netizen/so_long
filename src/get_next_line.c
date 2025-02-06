/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:06 by mmounsif          #+#    #+#             */
/*   Updated: 2025/02/06 17:19:25 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_from_file(int fd, char *stash);
static int	line_len(char *stash);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	stash = read_from_file(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	if (!ft_strchr(stash, '\n'))
	{
		line = ft_strdup(stash);
		return (free(stash), stash = NULL, line);
	}
	line = ft_substr(stash, 0, line_len(stash));
	temp = ft_strdup(stash + line_len(stash));
	free(stash);
	stash = temp;
	return (line);
}

static char	*read_from_file(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;
	char	*temp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
	}
	return (free(buf), stash);
}

static int	line_len(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	int fd;
// 	char *content;
// 	char *next_line;
// 	int count;

// 	fd = open("test.txt", O_CREAT | O_RDWR, 0644);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	content = "Hello, World\nthis is a test\nThank you for your time\n42";
// 	write(fd, content, strlen(content));
// 	lseek(fd, 0, SEEK_SET);
// 	count = 0;
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			break;
// 		count++;
// 		printf("Line %d: %s", count, next_line);
// 		free(next_line);
// 	}
// 	close(fd);
// }