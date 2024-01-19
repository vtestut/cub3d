/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:54:15 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 19:06:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*r;

// 	r = malloc(nmemb * size);
// 	if (!r)
// 		return (NULL);
// 	ft_bzero(r, size * nmemb);
// 	return (r);
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*arr;

// 	if (nmemb == 0 || size == 0)
// 		return (malloc(0));
// 	if ((size * nmemb) / nmemb != size)
// 		return (NULL);
// 	arr = malloc(nmemb * size);
// 	if (!arr)
// 		return (NULL);
// 	ft_bzero(arr, nmemb * size);
// 	return (arr);
// }

//GPT
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}