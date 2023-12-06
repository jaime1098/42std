/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:51:38 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/21 12:51:41 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>	
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*get_next_line(int fd);
int     ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);

#endif
