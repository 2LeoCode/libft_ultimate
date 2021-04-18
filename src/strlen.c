#include <libft.h>

static size_t	ft_strlen_basic(const char *s, const char *begin)
{
	while (*s)
		s++;
	return (s - begin);
}

static size_t	__ft_strlen(const unsigned char *s, const char *begin)
{
	if (!s[0])
		return ((size_t)s - (size_t)begin);
	if (!s[1])
		return ((size_t)s - (size_t)begin + 1LL);
	if (!s[2])
		return ((size_t)s - (size_t)begin + 2LL);
	if (!s[3])
		return ((size_t)s - (size_t)begin + 3LL);
	if (!s[4])
		return ((size_t)s - (size_t)begin + 4LL);
	if (!s[5])
		return ((size_t)s - (size_t)begin + 5LL);
	if (!s[6])
		return ((size_t)s - (size_t)begin + 6LL);
	if (!s[7])
		return ((size_t)s - (size_t)begin + 7LL);
	return (0);
}

static size_t	_ft_strlen(const unsigned long *long_ptr, const char *begin)
{
	if (HIMAGIC == -1)
		return (ft_strlen_basic((char *)long_ptr, begin));
	while (1)
	{
		if (((*long_ptr - LOMAGIC) & ~*long_ptr) & HIMAGIC)
			break ;
		long_ptr++;
	}
	return (__ft_strlen((unsigned char *)long_ptr, begin));
}

size_t	ft_strlen(const char *s)
{
	const char	*char_ptr = s;

	while (*char_ptr && ((size_t)char_ptr % sizeof(long)))
		char_ptr++;
	return (_ft_strlen((unsigned long *)char_ptr, s));
}
