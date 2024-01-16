/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:14:44 by vtestut          #+#    #+#             */
/*   Updated: 2023/06/15 22:16:29 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstappend(t_list lst, t_list new)
{
	t_list	tmp;

	tmp.list = lst.list->next;
	lst.list->next = new.list;
	new.list->next = tmp.list;
}
