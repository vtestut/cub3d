/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:58:34 by vtestut          #+#    #+#             */
/*   Updated: 2023/07/27 15:10:08 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# ifdef FT_LIST_CUSTOM_TYPE
#  include FT_LIST_CUSTOM_TYPE
# else
#  include "ft_list_type.h"
# endif
# include <sys/types.h>
# include <stdlib.h>
# include "ft_string.h"

/**
 * Create a new list
 * 
 * @param content		the new list content
 * 
 * @return the new list or NULL on failure
*/
t_list	ft_lstnew(void *content);

/**
 * Free the element pointed to by lst and all subsequent elements 
 * and free it's content using f
 * 
 * @param lst	the element from which to delete
 * @param f		the function to free the contents
 * 
 * @warning		f must not be NULL
*/
void	ft_lstclear(t_list lst, void (*f)(void *));

/**
 * Insert a new element at the beggining of the list
*/
void	ft_lstaddfront(t_list *lst, t_list new);

/**
 * Push a new element at the end of the list
*/
void	ft_lstaddback(t_list *lst, t_list new);

/**
 * Get the number of elements in the list
 * 
 * @param lst		the list
 * 
 * @return the number of elements in the list or 0 is the list is empty or NULL
*/
int		ft_lstsize(t_list lst);

/**
 * Return the last element of the list
 * 
 * @param lst		the list
 * 
 * @return the last element of the list or NULL if the list is empty
*/
t_list	ft_lstlast(t_list lst);

/**
 * Iterate over the list and apply f over each element of the list 
 * with i being the push_swap_index of each element
 * 
 * @param lst		the list
 * @param f			the function to operate over each element
 * 
 * @return 1 if f successed over each element, 0 else
*/
int		ft_lstiteri(t_list lst, int (*f)(size_t i, void *content));

/**
 * Return the nth element of lst, push_swap_index can be negative in which case
 * the function will return the nth element from the end
 * 
 * @param lst		the list
 * @param index		the push_swap_index to lookup
 * 
 * @return the element or NULL if none found
*/
t_list	ft_lstat(t_list lst, int index);

/**
 * Append new to lst
 * 
 * @param lst	the element to which append
 * @param new	the element to append
 * 
 * @warning new must not be NULL
*/
void	ft_lstappend(t_list lst, t_list new);

/**
 * Return the push_swap_index of the current node
 * 
 * @param begin		the beggining of the list
 * @param nd		the node
 * 
 * @return the push_swap_index of the node or -1 if none found
 * 
 * @warning begin must not be NULL
 * @warning nd must not be NULL
*/
int		ft_lstindex(t_list begin, t_list nd);

/**
 * Duplicate the list
 * 
 * @param lst		the list to duplicate
 * @param elem_size	the size of each element
 * 
 * @return the duplicated list or NULL on failure
*/
t_list	ft_lstdup(t_list lst, void *(*dup)(void *), void (*del)(void *));

#endif