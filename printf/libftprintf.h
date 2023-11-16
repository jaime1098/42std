/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joltra-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:11:59 by joltra-r          #+#    #+#             */
/*   Updated: 2023/11/16 13:12:01 by joltra-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(char const *text, ...);
int	ft_isc(va_list args);
int	ft_iss(va_list args);
int	ft_isp(va_list args);
int	ft_isid(va_list args);
int	ft_isu(va_list args);
int	ft_isxX(va_list args, const char *text);
int	ft_returns(const char *text, va_list args, int n);
int	main(void);

#endif
