#include <libft.h>

char	*ft_strjoin2(const char *s1, const char *s2, size_t len1, size_t len2)
{
	char			*s;
	const size_t	len_tot = len1 + len2;

	s = (char *)malloc(len_tot + 1);
	if (!s)
		return (NULL);
	s[len_tot] = '\0';
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	return (s);
}
