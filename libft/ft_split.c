/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastelb <acastelb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:41:13 by acastelb          #+#    #+#             */
/*   Updated: 2021/05/31 10:35:34 by acastelb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_size(const char *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	ft_words_count(char const *s, char c)
{
	int		count;
	int		len;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = ft_word_size(s, c);
		if (len)
		{
			s += len;
			count++;
		}
	}
	return (count);
}

static char	*ft_create_w(const char *s, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s[len];
	return (str);
}

static void	ft_free_tab(char **splited, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(splited[i]);
	free(splited);
}

char	**ft_split(char const *s, char c)
{
	int		words_nb;
	char	**splited;
	int		i;

	if (!s)
		return (NULL);
	words_nb = ft_words_count(s, c);
	splited = (char **)malloc(sizeof(char *) * (words_nb + 1));
	if (!(splited))
		return (NULL);
	i = -1;
	while (++i < words_nb)
	{
		while (*s == c && *s)
			s++;
		splited[i] = ft_create_w(s, ft_word_size(s, c));
		if (!(splited[i]))
		{
			ft_free_tab(splited, i);
			return (NULL);
		}
		s += ft_word_size(s, c);
	}
	splited[i] = NULL;
	return (splited);
}
