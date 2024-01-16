/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:48:13 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:28:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddfront(t_list *lst, t_list new)
{
	t_list	tmp;

	tmp = *lst;
	new.list->next = tmp.list;
	*lst = new;
}
