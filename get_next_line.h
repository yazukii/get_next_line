/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:28:01 by yidouiss          #+#    #+#             */
/*   Updated: 2022/11/09 16:24:56 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "unistd.h"
# include "stdlib.h"
# include "string.h"

char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t cout, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *str);

#endif
