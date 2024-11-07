/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:46:48 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/07 10:55:55 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_newline(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				len++;
				return (len);
			}
		}
		list = list->next;
	}
	return (len);
}

void	ft_copy(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buf[i])
		{
			if (list->buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

char	*ft_line(t_list *list)
{
	int		len;
	char	*next;

	if (NULL == list)
		return (NULL);
	len = ft_newline(list);
	next = malloc(len + 1);
	if (!next)
		return (NULL);
	ft_copy(list, next);
	return (next);
}

void	ft_lstadd(t_list **list)
{
    t_list *last_node;
    t_list *node;
    int i;
    int k;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    node = malloc(sizeof(t_list));
    if (buf == NULL || node == NULL)
        return ;
    last_node = ft_lstlast(*list);
    i = 0;
	k = 0;
    while (last_node->buf[i] && last_node->buf[i] != '\n')
            i++;
    while (last_node->buf[i])
            buf[k++] = last_node->buf[i++];
    buf[k] = '\0';
    node->buf = buf;
    node->next = NULL;
    ft_clear_list(list, node, buf);
}
void ft_clear_list(t_list **list, t_list *node, char *buf)
{
   t_list *tmp;

   if (*list == NULL)
   		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if(node->buf[0])
		*list = node;
	else
	{
		free(buf);
		free(node);
	}
}
