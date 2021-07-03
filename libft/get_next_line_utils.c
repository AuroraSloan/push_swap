#include "libft.h"

int	err_free1(char *s1)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (-1);
}

int	err_free2(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (-1);
}
