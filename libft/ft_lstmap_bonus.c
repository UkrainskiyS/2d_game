/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:35:39 by                   #+#    #+#             */
/*   Updated: 2021/10/10 00:17:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	**run_lstmap(t_list **copy_lst, t_list *lst, void *(*f)(void
*), void (*del)(void *))
{
	t_list	*help_list;
	void	*list_content;

	while (lst)
	{
		list_content = f(lst->content);
		if (!list_content)
		{
			ft_lstclear(copy_lst, del);
			return (NULL);
		}
		help_list = ft_lstnew(list_content);
		if (!help_list)
		{
			ft_lstclear(copy_lst, del);
			return (NULL);
		}
		ft_lstadd_back(copy_lst, help_list);
		lst = lst->next;
	}
	return (copy_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy_lst;
	void	*list_content;

	if (!lst)
		return (NULL);
	list_content = f(lst->content);
	if (!list_content)
	{
		del(list_content);
		return (NULL);
	}
	copy_lst = ft_lstnew(list_content);
	lst = lst->next;
	run_lstmap(&copy_lst, lst, f, del);
	return (copy_lst);
}
