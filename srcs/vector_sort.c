//
// Created by peerdb on 03-07-21.
//

#include "vector.h"
#include <stdio.h>

void	swap(CONTENT *a, CONTENT *b)
{
	const int	tmp = *a;

	*a = *b;
	*b = tmp;
}

static size_t	find_desired_position(t_vector *vec, CONTENT nb)
{
	size_t	i;

	i = 0;
	while (vec->arr[i] < nb)
		++i;
	return (i);
}

static void	reinsert(t_vector *vec, size_t index)
{
	const CONTENT	value = vec->arr[index];
	size_t			desired_pos;

	desired_pos = find_desired_position(vec, value);
	while (index > desired_pos)
	{
		vec->arr[index] = vec->arr[index - 1];
		--index;
	}
	vec->arr[desired_pos] = value;
}

void	vector_sort(t_vector *vec)
{
	size_t	i;

	i = 1;
	while (i < vec->size)
	{
		if (vec->arr[i] < vec->arr[i - 1])
			reinsert(vec, i);
		++i;
	}
}