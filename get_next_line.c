/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:46:39 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/07 10:54:58 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
			i++;
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
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_new_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_line(list);
	ft_lstadd(&list);
	return (next_line);
}
