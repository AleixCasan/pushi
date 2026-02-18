/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilla-c <smilla-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:42:41 by smilla-c          #+#    #+#             */
/*   Updated: 2026/02/17 12:43:34 by smilla-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t	s_len;
    size_t	i;
    char	*ptr;

    if (!s)
        return (NULL);
    s_len = ft_strlen (s);
    if (start >= s_len)
        len = 0;
    if (len > s_len - start)
        len = s_len - start;
    ptr = (char *)malloc(sizeof(char)*(len + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
size_t  count_words(const char *s, char c)
{
    size_t  word;

    word = 0;
    while (*s)
    {
        if (*s == c)
            s++;
        if (*s && *s != c)
            word++;
        while (*s && *s != c)
            s++;
    }
    return (word);
}

char    **ft_split(const char *s, char c)
{
    size_t  word;
    size_t  i;
    char    **lst;

    if (!s)
        return (NULL);
    lst = (char **)malloc(sizeof(char *)*(count_words(s, c) + 1));
    if (!lst)
        return (NULL);
    i = 0;
    while (*s)
    {
        if (*s == c)
            s++;
        word = 0;
        while (s[word] && s[word] != c)
            word++;
        if (word)
            lst[i++] = ft_substr (s, 0, word);
        s += word;
    }
    lst[i] = NULL;
    return (lst);
}
