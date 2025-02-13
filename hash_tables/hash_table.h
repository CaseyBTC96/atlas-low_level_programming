#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
 * struct shash_node_s - Node of a hash table
 * @key: The key, a string
 * @value: The value corresponding to a key
 * @next: Pointer to the next node in the list (for chaining)
 * @sprev: Pointer to the previous element in the sorted list
 * @snext: Pointer to the next element in the sorted list
 */
typedef struct shash_node_s
{
	char *key;  /* The key, string */
	char *value; /* The value corresponding to a key */
	struct shash_node_s *next; /* Ptr to next node in the list */
	struct shash_node_s *sprev; /* Ptr to prev elem in the sorted list */
	struct shash_node_s *snext; /* Ptr to next elem in the sorted list */
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table
 * @size: The size of the array
 * @array: Array of pointers to the first node of the linked list
 * @shead: Pointer to the first element of the sorted linked list
 * @stail: Pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size; /* The size of the array */
	shash_node_t **array; /* Array of Ptrs to first node of linked list */
	shash_node_t *shead;  /* Ptr to first elem of the sorted linked list */
	shash_node_t *stail;  /* Ptr to last elem of the sorted linked list */
} shash_table_t;


/* Function prototypes */
/**
 * shash_table_create - Creates a new sorted hash table
 * @size: The size of the array
 * Return: A pointer to the newly created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size);

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
