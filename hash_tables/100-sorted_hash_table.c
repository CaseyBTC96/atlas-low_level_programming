#include "hash_tables.h"

/**
* shash_table_create - Creates a sorted hash table.
* @size: The size of the array.
*
* Return: A pointer to the new created hash table, or NULL on a failure.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;

	new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));
	new_table->shead = NULL;
	new_table->stail = NULL;

	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}

	return (new_table);
}
