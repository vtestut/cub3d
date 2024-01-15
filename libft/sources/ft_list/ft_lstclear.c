/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:02:51 by vtestut          #+#    #+#             */
/*   Updated: 2023/06/14 18:04:31 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstclear(t_list lst, void (*f)(void *content))
{
	t_list	tmp;

	if (!lst.list)
		return ;
	while (lst.list)
	{
		tmp.list = lst.list->next;
		f(lst.list->content);
		free(lst.list);
		lst = tmp;
	}
}
