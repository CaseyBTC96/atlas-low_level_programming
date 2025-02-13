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

/**
* shash_table_set - Adds an element to the sorted hash table.
* @ht: The sorted hash table.
* @key: The key.
* @value: The value.
*
* Return: 1 if successful, 0 otherwise.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *temp_node;
	shash_node_t *current, *prev;

	if (!ht || !key || !value)
		return (0);
	index = hash_djb2((unsigned char *)key) % ht->size;
	temp_node = ht->array[index];
	for (; temp_node; temp_node = temp_node->next)
		if (!strcmp(temp_node->key, key))
			return (free(temp_node->value), temp_node->value = strdup(value), 1);
	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key), new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	current = ht->shead, prev = NULL;  /* Insert into sorted linked list */
	while (current && strcmp(current->key, key) < 0)
	{
		prev = current, current = current->snext;
	}
	if (current && strcmp(current->key, key) == 0)
	{
		free(current->value);
		current->value = strdup(value);
		free(new_node->key), free(new_node->value), free(new_node);
		return (1);
	}
	new_node->snext = current;
	new_node->sprev = prev;
	if (prev)
		prev->snext = new_node;
	else
		ht->shead = new_node;
	if (current)
		current->sprev = new_node;
	else
		ht->stail = new_node;
	return (1);
}

