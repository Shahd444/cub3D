/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:57:20 by sshawish          #+#    #+#             */
/*   Updated: 2025/04/29 12:47:20 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	void	*content;
	void	*temp_content;

	save = NULL;
	while (lst)
	{
		content = lst->content;
		temp_content = f(content);
		new_list = ft_lstnew(temp_content);
		if (!new_list)
		{
			del(temp_content);
			ft_lstclear(&save, del);
			return (NULL);
		}
		ft_lstadd_back(&save, new_list);
		lst = lst->next;
	}
	return (save);
}
