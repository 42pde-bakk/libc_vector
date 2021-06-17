//
// Created by peerdebakker on 14-04-21.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	fakemain(void)
{
	t_vector*	vec;
	int			i;

	i = 0;
	vec = vector_init(0);
	while (i < 30)
	{
		vector_pushback(vec, i);
		++i;
	}
	printf("Capacity is %zu\n", vec->capacity);
	i = 0;
	vector_delete_byval(vec, 10);
	vector_delete_bypos(vec, 10);
	vector_delete_bypos(vec, 13);
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%d}\n", i, vec->arr[i]);
		++i;
	}
	vector_destroy(vec);
	return (0);
}

int	main(void)
{
	fakemain();
	return (0);
}
