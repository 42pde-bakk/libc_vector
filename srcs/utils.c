//
// Created by peerdebakker on 14-04-21.
//

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	fatal_error(const char *s)
{
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	*malloc_wrapper(size_t size)
{
	void	*out;

	out = malloc(size);
	if (!out)
		fatal_error("Error");
	return (out);
}

void	*calloc_wrapper(size_t nmemb, size_t size)
{
	void	*out;

	out = ft_calloc(nmemb, size);
	if (!out)
		fatal_error("Error");
	return (out);
}
