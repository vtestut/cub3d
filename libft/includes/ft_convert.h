/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:59:04 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 11:47:07 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "libft.h

/**
 * @brief Transforms a string of digits into a long integer.
 * 
 * @param str 
 * @param error 
 * @return Returns the long integer. In case of error, sets an error boolean
 * to true.
 */
int		ft_atoi_long(const char *str, bool *error);

/**
 * Convert the string str into i
 * @param str
 * @return
 */
int		ft_atoi(const char *str);

/**
 * Get the string equivalent of val
 * 
 * @param val		the value to convert
 * 
 * @return			a statically allocated string or NULL on failure
*/
char	*ft_itoa(int64_t val);

int		ft_strtoi(const char *str, char **endptr, int base);

/**
 * Convert the initial portion of s into a long integer according to the
 * given base, if successful *endptr == s evaluate to true
 *
 * @param s		the string to be converted
 * @param endptr
 * @param base		the base in which to convert
 * @return
 *
 * @warning			if the specified base is different from 8, 10 or 16
 * 					the function behavior is undefined
 * @warning			s must be not NULL
 * @warning			*endptr should point to something other than s (in case
 * 					of)
 */
long	ft_strtol(const char *s, char **endptr, int base);

#endif
