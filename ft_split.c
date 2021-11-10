/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:30:09 by yoelhaim          #+#    #+#             */
/*   Updated: 2021/11/10 10:45:51 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_size(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static	char	**fill_array(char **array, char const *s, char c)
{
	int	i;
	int	temp;
	int	index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			temp = i;
			while (s[i] != c && s[i])
				i++;
			array[index] = malloc(i - temp + 1);
			if (!array[index])
				return (NULL);
			ft_strlcpy(array[index++], s + temp, i - temp + 1);
		}
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_size(s, c);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill_array(array, s, c))
	{
		return (NULL);
	}
	return (array);
}
// int main()
// {
// 	char **arr = ft_split("helloe every one", ' ');
// 	int i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		printf("%s", arr[i]);
// 		i++;
// 	}

// }
