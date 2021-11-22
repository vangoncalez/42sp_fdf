/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:13 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/06 22:46:42 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = (ft_strlen((char *)s1));
	len2 = (ft_strlen((char *)s2));
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(&str[0], s1, len1 + 1);
	ft_strlcpy(&str[len1], s2, len2 + 1);
	return (str);
}
