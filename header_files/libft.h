/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:00:10 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/19 12:57:54 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "definitions.h"

int				ft_isalpha(int c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
long			ft_atoi(const char *nptr);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *nw);
void			ft_lstadd_back(t_list **lst, t_list *nw);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst);
void			ft_lstclear(t_list **lst);
int				ft_strcmp(const char *s1, const char *s2);
size_t      	ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strjoin(char *s1, char *s2);

#endif
