/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:34 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/24 17:09:41 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The function ft_split() allocates memory (using malloc(3)) and returns
an array of strings resulting from splitting the string s
using the character c as a delimiter.
The returned array of strings is terminated with a NULL pointer.*/

#include "libft.h"
#include <stdlib.h>

static int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_getword(char const *s, char c)
{
	size_t	word_len;
	char	*word;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word_len = 0;
	while (*s && *s != c)
		word[word_len++] = *s++;
	word[word_len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			lst[i++] = ft_getword(s, c);
			s += ft_strlen(lst[i - 1]);
		}
	}
	lst[i] = NULL;
	return (lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **words = ft_split("", ' ');
// 	printf("word : %s \n", words[0]);
// }