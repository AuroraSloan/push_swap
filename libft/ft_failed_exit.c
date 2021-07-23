#include "libft.h"
#include <unistd.h>

void	ft_failed_exit(char *message, char *memory)
{
	if (memory)
	{
		ft_free(memory);
		memory = NULL;
	}
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
