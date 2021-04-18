#include <libft.h>

char	*ft_strndup2(const char *s1, size_t len, size_t n)
{
	char			*s;

	if (len < n)
		n = len;
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	s[n] = '\0';
	return ((char *)ft_memcpy(s, s1, n));
}
