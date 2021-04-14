//
// Created by peerdebakker on 14-04-21.
//

#include "vector.h"
#include <stdio.h>

int fakemain(void) {
	t_vector	*vec;
	int i = 0;

	vec = vector_init(10);
	while (i < 30) {
		vector_pushback(vec, i);
		++i;
	}

	printf("Capacity is %zu\n", vec->capacity);
	i = 0;
	while ((size_t)i < vec->size)
	{
		printf("vec[%d]: {%d}\n", i, vec->arr[i]);
		++i;
	}
	vector_destroy(vec);
	return (0);
}

int main() {
	fakemain();
	return (0);
}