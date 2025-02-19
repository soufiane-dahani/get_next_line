/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/08/12 12:52:22 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/13 21:38:23 by sodahani         ###   ########.fr       */
=======
/*   Created: 2024/11/05 10:46:39 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/11 16:15:27 by sodahani         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
<<<<<<< HEAD

static char	*ft_fill_line_buffer(int fd, char *remains, char *buffer)
{
	ssize_t	nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(remains);
			return (NULL);
		}
		else if (nbytes == 0)
			break ;
		buffer[nbytes] = 0;
		if (!remains)
			remains = ft_strdup("");
		tmp = remains;
		remains = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remains);
}

static char	*ft_separate_lines(char *line_buffer)
{
	char	*remain_lines;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	remain_lines = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!remain_lines)
	{
		free(remain_lines);
		remain_lines = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (remain_lines);
=======
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_append(t_list **list, char *buf1)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buf = buf1;
	new_node->next = NULL;
}

int	ft_check_line(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buf[i] && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	create_new_list(t_list **list, int fd)
{
	int		read_value;
	char	*buf1;

	while (!ft_check_line(*list))
	{
		buf1 = malloc(BUFFER_SIZE + 1);
		if (NULL == buf1)
			return ;
		read_value = read(fd, buf1, BUFFER_SIZE);
		if (!read_value)
		{
			free(buf1);
			return ;
		}
		buf1[read_value] = '\0';
		ft_append(list, buf1);
	}
>>>>>>> main
}

char	*get_next_line(int fd)
{
<<<<<<< HEAD
	static char	*remains;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(remains);
		buffer = NULL;
		remains = NULL;
		return (NULL);
	}
	line = ft_fill_line_buffer(fd, remains, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remains = ft_separate_lines(line);
	return (line);
}
=======
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_new_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = list->buf;
	return (next_line);
}
#include <stdio.h>
int main() {
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
>>>>>>> main
