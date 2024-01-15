/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:15:35 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/15 18:02:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <sys/types.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_ctype.h"

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

int		ft_strtoi(const char *str, char **endptr, int base);

/**
 * Convert the string str into i
 * @param str
 * @return
 */
int		ft_atoi(char *str);

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
 * @brief Return a new memory area of new_size bytes containing the first 
 * old_size bytes of ptr
 * 
 * Return a new memory area of size bytes containing the first new_siz
 *  bytes of ptr, if new_size is smaller than size, the content is truncated,
 * if new_size is bigger than size, the content is extended with '\0' bytes. 
 * If ptr is NULL, the function behaves like malloc, if new_size is 0, the 
 * function behaves like free. 
 * If the allocation fails, the function returns NULL and ptr is left untouched.
 * 
 * @param ptr		The old memory area 
 * @param old_size 		The old size
 * @param new_size	The new size
 * 
 * @return The new memory area on success, NULL otherwise
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/**
 * allocates memory for an array of  nmemb  elements of size bytes each.
 * The memory is set to zero
 * 
 * @param nmemb     the number of elements
 * @param size
 * 
 * @return          a pointer to the allocated memory
*/
void	*ft_calloc(size_t nmemb, size_t size);

#endif
