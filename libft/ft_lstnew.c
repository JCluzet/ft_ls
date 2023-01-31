/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:03:32 by jcluzet           #+#    #+#             */
/*   Updated: 2019/11/28 09:22:08 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (nouveau == NULL)
		return (NULL);
	nouveau->content = content;
	nouveau->next = NULL;
	return (nouveau);
}
