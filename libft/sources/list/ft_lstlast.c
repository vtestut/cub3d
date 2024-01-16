/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:53:22 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:28:45 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	ft_lstlast(t_list lst)
{
	if (!lst.list)
		return ((t_list){.list = NULL});
	while (lst.list->next)
		lst.list = lst.list->next;
	return (lst);
}
