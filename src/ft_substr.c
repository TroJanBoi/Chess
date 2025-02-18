#include "../include/chess.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = strlen(s);
	if (start > str_len)
		len = 0;
	else if (len > (str_len - start))
		len = str_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	s += start;
	ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (ptr);
}