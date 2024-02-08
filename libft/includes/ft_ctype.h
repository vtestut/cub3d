/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:40:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include "libft.h"

/**
 * @brief 		Check if the character is an alphabetic char or a numeral
 * @return 		1 if the character is alpha or num, 0 else
 */
int		ft_isalnum(int c);

/**
 * @brief 		Check if a given character is alphabetic
 * @return		1 if true, 0 else
 */
int		ft_isalpha(int c);

/**
 * @brief 		Check if a given string is composed of alphabetic characters
 * @return		1 if true, 0 else
 * @warning		str must be null-terminated
 * @warning		str must not be null
 */
int		ft_isalphastr(const char *str);

/**
 * @brief		Check if the given character is part of the ASCII table
 * @return		1 if true, 0 else
 */
int		ft_isascii(int c);

/**
 * @brief		Check if a given character is a digit
 * @return		1 if true, 0 else
 */
int		ft_isdigit(int c);

/**
 * @brief		Check if a given string is composed of digit characters
 * @return		1 if true, 0 else
 * @warning		str must be null-terminated
 * @warning		str must not be null
*/
int		ft_isdigitstr(const char *str);

/**
 * @brief 		Check if a given character is "printable"
 * @return		1 if true, 0 else
 */
int		ft_isprint(int c);

/**
 * @brief		Check if a given character is a space
 * @return		1 if true, 0 else
*/
int		ft_isspace(int c);

#endif
