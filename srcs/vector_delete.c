//
// Created by peerdebakker on 17-06-21.
//

void	vector_destroy(t_vector *vec)
{
	free(vec->arr);
	vec->arr = NULL;
	free(vec);
}

void	vector_delete_bypos(t_vector *vec, size_t pos)
{
	if (pos >= vec->size)
		return ;
	while (pos < vec->size)
	{
		vec->arr[pos] = vec->arr[pos + 1];
		++pos;
	}
	--vec->size;
}

// finds the first occurence of item and deletes it
// right now only works for ints and chars, not strings

void	vector_delete_byval(t_vector *vec, CONTENT item)
{
	size_t	pos;

	pos = 0;
	while (pos < vec->size)
	{
		if (vec->arr[pos] == item)
		{
			vector_delete_bypos(vec, pos);
			return ;
		}
		++pos;
	}
}
