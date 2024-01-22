/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:43:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/20 14:42:34 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

# include "libft.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(const char *str, int fd);

#endif