/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:29:09 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 15:16:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "libft.h"

/**
 * Count the number of characters matching c in str.
 *
 * @param	str	the string
 * @param	c	the character
 *
 * @return		the number of character in str matching c
 *
 * @warning		str must be null terminated
 * @warning		str must not be null
 */
size_t	ft_countc(const char *str, int c);

/**
 * Count the number of character in str matching the characters in charset.
 *
 * @param	str		the string
 * @param	charset	the charset
 *
 * @return			the number of character in str matching the charset
 *
 * @warning			str must be null terminated
 * @warning			str must not be null
 * @warning			charset must be null terminated
 * @warning			charset must not be null
 *
 * @example			ft_countcs
 */
size_t	ft_countcs(const char *str, const char *charset);

int		ft_intlen(int n);

int		ft_longlen(unsigned int n);

void	ft_putlong(unsigned int nb);

/**
 * Rotate the element of arr in the given direction
 * 
 * @param arr		the array to rotate
 * @param direction	the direction and number of element in which to rotate
 * @param n			the number of element in the array
 * @param size		the size of one element
 * 
 * @warning			arr must not be NULL
*/
void	ft_rotate(void *arr, int direction, size_t n, size_t size);

char	**ft_split(const char *str, int c);

char	**ft_splitcs(const char *str, const char *charset);

/**
 * @brief Allocate a new string being the concatenation of s1 and s2
 *
 * @param s1
 * @param s2
 * @return 		The new string on succes or NULL on error
 */
char	*ft_strcat(const char *s1, const char *s2);

/**
 * Return a pointer to the first occurence of c in str
 *
 * @param	str	the string to search in
 * @param	c	the character to search for
 *
 * @return		a pointer over the first occurence of c in str or NULL if
 * none found
 *
 * @warning		str must be null terminated
 * @warning		str must not be null
 */
char	*ft_strchr(const char *str, int c);

/**
 * Find the first occurence of a character of charset in str
 * 
 * @param str		the string to search in
 * @param charset	the character set
 * 
 * @return			the first occurence of a character of charset in str
 * 					or NULL if none found
*/
char	*ft_strchr1(const char *str, const char *charset);

/**
 * Compare the string s1 and s2
 * @param s1
 * @param s2
 * @return 	A positive integer if s1 > s2, a negative one if s1 < s2
 * 			or 0 if s1 == s2
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * copies the string pointed to by src, to the buffer pointed to by dest.
 * 
 * @param dest		pointer to the dest buffer 
 * @param src		pointer to the source string
 * 
 * @return			a pointer to the destination string
 * 
 * @warning			dest string must be large enough to receive the copy
 * @warning			beware of of buffer overruns!
 */
char	*ft_strcpy(char *dest, const char *src);

/**
 * Duplicate the string pointed to by str
 *
 * @param str
 *
 * @return		The new string or NULL on error
 *
 * @warning		str must not be NULL
 */
char	*ft_strdup(const char *str);

/**
 * Copy str and insert what into str after character begin
 * 
 * @param src		the original string
 * @param begin		the character after which to delete
 * @param what		the string to insert
 * 
 * @return			the new string on success or NULL on error
*/
char	*ft_strinsert(const char *src, const char *begin, const char *what);

/**
 * Copy str and insert what into str after character begin
 *
 * @param src		the original string
 * @param begin		the starting index
 * @param what		the string to insert
 *
 * @return		the new string on success or NULL on error
 */
char	*ft_strinsertn(const char *src, size_t begin, const char *what);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * concatenates the given strings s1 and s2 and allocates sufficient
 * memory for the newly created string
 * 
 * @param s1	the string which to attach the second string
 * @param s2	the string to attach to the first string
 * 
 * @return		A pointer to the new concatenated string
 * 				NULL if the memory allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * copies up to size - 1 characters from the given string src to the
 * given string dst, nul-terminating the result.
 * 
 * @warning 	space for the terminating \0 character must be included in dstsize.
 * 
 * @return 		The total length of the string that it tried to create
 * 				the length of src, with the goal to facilitate truncaction detection
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * Return the number of character into the null terminated string str
 *
 * @param	str	the string
 * @return		the number of character in the string
 * @warning		str must be null-terminated
 * @warning		str must not be null
 */
// int		ft_strlen(const char *str);
size_t	ft_strlen(const char *str);


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Same as ft_strcmp but compare only the first n bytes of s1 and s2
 * @param s1
 * @param s2
 * @param n
 * @return
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * copies the string pointed to by src, to the buffer pointed to by dest.
 * 
 * @param dest		pointer to the dest buffer 
 * @param src		pointer to the source string
 * @param n			nb of bytes copied from src
 * 
 * @return			a pointer to the destination string
 * 
 * @warning			dest string must be large enough to receive the copy
 * @warning			If there is no \0 in n-bytes of src, dest will not be 
 * 					null-terminated.
 * @warning			beware of of buffer overruns!
 */
char	*ft_strncpy(char *dest, const char *src, size_t n);

/**
 * Duplicate at most n characters of str
 *
 * @param str
 * @param n		The maximum number of character to copy, not taking 
 * 				the NULL byte into account
 *
 * @return 		The new string or NULL on error, the new string will
 * 				be n + 1 bytes long
 *
 * @warning		str must not be null
 */
char	*ft_strndup(const char *str, size_t n);

/**
 * Return the number of character into the null terminated string str
 *
 * @param	str	the string
 * @param	n	the maximum number of characters to count
 * @return		the number of character in the string
 * @warning		str must be null-terminated
 * @warning		str must not be null
 */
size_t	ft_strnlen(const char *str, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Return a pointer to the last occurence of c in str
 *
 * @param	str	the string to search in
 * @param	c	the character to search for
 *
 * @return		a pointer over the last occurence of c in str
 *
 * @warning		str must be null terminated
 * @warning		str must not be null
 */
char	*ft_strrchr(const char *str, int c);

/**
 * Copy str and remove from begin to end and then return it
 * 
 * @param src		the original string
 * @param begin		the character from which to delete (included)
 * @param end		the character from which not to delete (not included)
 * 
 * @return			the new string or NULL on error
*/
char	*ft_strremove(const char *src, const char *begin, const char *end);

/**
 * Copy str and remove n characters starting from begin
 *
 * @param src		the original string
 * @param begin		the starting index
 * @param n			how many characters to remove
 *
 * @return		the new string or NULL on error
 */
char	*ft_strremoven(const char *src, size_t begin, size_t n);

/**
 * Copy str, remove the character between begin and end and insert
 * what after begin
 * 
 * @param src		the original string
 * @param begin		the character from which to remove (included)
 * @param end		the character from which not to delete (not included)
 * @param what		the string to insert after begin
 * 
 * @return			the new string on success or NULL on error
*/
char	*ft_strreplace(const char *src, const char *begin,
			const char *end, const char *what);

char	*ft_strreplacen(const char *src, size_t begin, \
		size_t n, const char *what);

/**
 * Remove the first character of set in str from the righmost
 * and leftmost part of str
 * @param str
 * @param set
 * @return 		The number of removed characters
 */
int		ft_strtrim_one(char *str, const char *set);

/**
 * Remove the character of set from the righmost and leftmost part of str
 *
 * @param str
 * @param set
 * @return		The number of removed characters
 */
int		ft_strtrim(char *str, const char *set);

/**
 * Extracts a substring from the given string by allocating sufficient memory
 * for the new string starting at index start and ending at len characters.
 * 
 * @param s		the string
 * @param start the character the new string will start at
 * @param len	len of the substracted string
 * 
 * @return		A pointer to the new string.
 * 				NULL if the memory allocation fails.
*/
char	*ft_substr(char const *src, unsigned int start, int len);

/**
 * @brief Return the lowercase equivalent of c
 * 
 * @param c 
 * @return The lowercase equivalent of c if c is uppercase, else return c
 */
int		ft_tolower(int c);

/**
 * @brief Return the uppercase equivalent of c
 * 
 * @param c 
 * @return The uppercase equivalent of c if c is lowercase, else return c
 */
int		ft_toupper(int c);

#endif
