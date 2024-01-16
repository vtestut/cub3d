/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:09:54 by vtestut          #+#    #+#             */
/*   Updated: 2023/06/16 18:21:21 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_math.h"

t_list	ft_lstat(t_list lst, int index)
{
	size_t	i;
	size_t	at;

	i = ft_absi(index);
	if ((int)i >= ft_lstsize(lst))
		return ((t_list){.list = NULL});
	if (index < 0)
		at = ft_lstsize(lst) + index;
	else
		at = index;
	while (at--)
		lst.list = lst.list->next;
	return (lst);
}
