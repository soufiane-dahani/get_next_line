/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/08/12 12:52:17 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/13 19:20:45 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
=======
/*   Created: 2024/11/05 10:46:53 by sodahani          #+#    #+#             */
/*   Updated: 2024/11/07 15:28:54 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				create_new_list(t_list **list, int fd);
void				ft_append(t_list **list, char *buf1);
t_list				*ft_lstlast(t_list *lst);
int					ft_check_line(t_list *list);
char				*ft_line(t_list *list);
int					ft_newline(t_list *list);
void				ft_lstadd(t_list **list);
void				ft_copy(t_list *list, char *str);
void				ft_clear_list(t_list **list, t_list *node, char *buf);
>>>>>>> main
#endif