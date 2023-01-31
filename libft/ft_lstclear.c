/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:47:53 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/29 21:19:51 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *next;

	if (!*lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
