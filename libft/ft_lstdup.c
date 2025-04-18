/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:12:11 by lucas             #+#    #+#             */
/*   Updated: 2024/12/04 09:09:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(const t_list *lst, size_t size)
{
	t_list	*res;
	t_list	*new;
	void	*new_content;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		new_content = ft_calloc(1, size);
		if (!new_content)
			return (ft_lstclear(&res, free), NULL);
		ft_memcpy(new_content, lst->content, size);
		new = ft_lstnew(new_content);
		if (!new)
		{
			free(new_content);
			return (ft_lstclear(&res, free), NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
