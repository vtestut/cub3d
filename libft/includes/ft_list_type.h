/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:27 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:01:28 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_TYPE_H
# define FT_LIST_TYPE_H

typedef union __attribute((transparent_union)) u_list {
	struct s_list {
		void			*content;
		struct s_list	*next;
	} *list;
}	t_list;

#endif
