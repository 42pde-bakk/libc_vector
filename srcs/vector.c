//
// Created by peerdebakker on 13-04-21.
//

#include "vector.h"
#include "utils.h"
#include <stdlib.h>

static void	vector_realloc(t_vector *vec, size_t newsize)
{
	size_t	i;
	CONTENT	*new_arr;

	new_arr = calloc_wrapper(newsize + 1, sizeof(CONTENT));
	i = 0;
	while (i < vec->size)
	{
		new_arr[i] = vec->arr[i];
		++i;
	}
	free(vec->arr);
	vec->arr = new_arr;
	vec->capacity = newsize;
}

t_vector	*vector_init(size_t init_size)
{
	t_vector	*vec;

	vec = calloc_wrapper(1, sizeof(t_vector));
	vec->capacity = init_size;
	vec->arr = calloc_wrapper(init_size + 1, sizeof(CONTENT));
	return (vec);
}

void	vector_destroy(t_vector *vec)
{
//	size_t	i;
//
//	i = 0;
//	if (sizeof(CONTENT) == sizeof(char*))
//	{
//		while (i < vec->size)
//		{
//			free(vec->arr[i]);
//			++i;
//		}
//	}
	free(vec->arr);
	free(vec);
}

#include <stdio.h>

void	vector_pushback(t_vector *vec, CONTENT item)
{
	if (vec->size == vec->capacity) {
		vector_realloc(vec, vec->capacity * 2);
	}
	vec->arr[vec->size] = item;
	++vec->size;
}

//static void	delete_pos(t_vector *vec, size_t pos)
void	vector_delete_bypos(t_vector *vec, size_t pos)
{
	if (pos >= vec->size)
		return;
	//if it is a pointer, free it?
//	if (sizeof(CONTENT) == sizeof(char*))
//		free(vec->arr[pos]);
	while (pos < vec->size)
	{
		vec->arr[pos] = vec->arr[pos + 1];
		++pos;
	}
}

void	vector_delete_byval(t_vector *vec, CONTENT item)
{
	size_t	pos;

	pos = 0;
	while (vec->arr[pos])
	{
		if (vec->arr[pos] == item)
		{
			vector_delete_bypos(vec, pos);
			return;
		}
	}
}
