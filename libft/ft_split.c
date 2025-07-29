/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:29:33 by sshawish          #+#    #+#             */
/*   Updated: 2025/04/29 12:52:51 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	ft_free(char **split, int i)
{
	if (!split[i])
	{
		while (i-- > 0)
			free(split[i]);
		free(split);
		return (0);
	}
	return (1);
}

static char	*ft_word_dup(const char *s, size_t len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	const char	*start;
	char		**split;
	int			i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*start && *start != c)
				start++;
			split[i++] = ft_word_dup(s, (start - s));
			if (!ft_free(split, i - 1))
				return (NULL);
			s = start;
		}
	}
	split[i] = NULL;
	return (split);
}
/*
#include<stdio.h>
int     main()
{
    char **split = ft_split("hello this is split", ' ');
    for (int i = 0; split[i]; i++)
    {
        printf("my fun :%s\n", split[i]);
    }
    return 0;
}
*/
