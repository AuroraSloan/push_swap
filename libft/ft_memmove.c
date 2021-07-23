#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_ptr;
	unsigned char		*dst_ptr;
	size_t			i;

	src_ptr = (const unsigned char *)src;
	dst_ptr = (unsigned char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (i < len)
		{
			dst_ptr[len - 1] = src_ptr[len - 1];
			dst_ptr--;
			src_ptr--;
			i++;
		}
	}
	return (dst);
}
