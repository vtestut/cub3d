/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:04:02 by vtestut            #+#    #+#             */
/*   Updated: 2023/10/11 16:01:18 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddback(t_list *lst, t_list new)
{
	t_list	last;

	last = ft_lstlast(*lst);
	if (!last.list)
		lst->list = new.list;
	else
		last.list->next = new.list;
}
