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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *text, ...);
int		ft_isc(va_list args);
int		ft_iss(va_list args);
int		ft_isp(va_list args);
int		ft_isid(va_list args);
int		ft_isu(va_list args);
int		ft_isx(va_list args, const char *text);
int		ft_returns(const char *text, va_list args, int n);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_putstr_fd(char *c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_unsigneditoa(unsigned int n);
void	ft_putunbr_fd(unsigned int nb, int fd);

#endif