/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:35:39 by                   #+#    #+#             */
/*   Updated: 2021/10/09 23:37:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_for_list(t_list *list, void (*del)(void *))
{
	if (!list)
		return ;
	free_for_list(list->next, del);
	del(list->content);
	free(list);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!*lst)
		return ;
	free_for_list(*lst, del);
	*lst = NULL;
}
