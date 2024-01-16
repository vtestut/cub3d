/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:36:59 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:47:31 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "libft.h"

/**
 * erases the data in the n bytes of the memory starting at the location 
 * pointed to by s, by writing zeros (bytes containing '\0') to that area.
 * 
 * @param s		pointer to the location
 * @param n		number of bytes that must be replaced by '\0'
 * 
 * @return		none
*/
void	ft_bzero(void *s, size_t n);

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

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Copy n bytes from src to dest.
 *
 * @param	dest	destination buffer
 * @param	src		source buffer
 * @param	n		number of bytes to copy
 *
 * @return			dest
 *
 * @warning			source and dest must be at least n bytes long
 * @warning			null check are not performed
 * @warning			memory must not overlap
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Duplicate the first n bytes of src
 * 
 * @param src		the source buffer
 * @param n			the number of bytes to copy
 * 
 * @return			the new buffer on success or NULL on error
 * 
 * @warning			src must not be NULL
 * @warning			src must be at least n bytes long
*/
void	*ft_memdup(void *src, size_t n);

/**
 * Repeat copy src in dest, if n < srclen then the first n bytes of 
 * src will be copied, if n > srclen dest will be filled with src
 * and if n % srclen != 0 then the last src will not be entirely copied
 * 
 * @param dest		the destination buffer
 * @param src		the source buffer
 * @param srclen	the size of the source buffer
 * @param n			the size of the dest buffer
 * 
 * @return			dest
*/
void	*ft_memelemset(void *dest, void *src, size_t srclen, size_t n);

/**
 * @brief Copy n bytes from src to dest, memory can overlap
 *
 * @param dest 		destination buffer
 * @param src		source buffer
 * @param n			number of bytes to copy
 * 
 * @return			dest
 * 
 * @warning			source and dest must be at least n bytes long
 * @warning			null check are not performed
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Set the first n bytes of dest to the value v.
 *
 * @param	dest	the destination buffer
 * @param	v		the value that will be taken by each byte
 * @param	n		the number of bytes to set
 *
 * @return			dest
 *
 * @warning			dest must not be null
 * @warning			dest must be at least n bytes long
 */
void	*ft_memset(void *dest, int v, size_t n);

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

#endif
