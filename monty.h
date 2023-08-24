#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct monty_s
{
	FILE *file;
	char *data;
	char *line;
} monty_t;
extern monty_t monty;

void push(stack_t **top, unsigned int Line_number);
void pall(stack_t **top, unsigned int Line_number);
void free_stack(stack_t *stack);
void *delete_spaces(char *prompt);
int _isspace(int c);
bool is_integer(char *str);
bool is_whitespace(char c);
int count_args(char *line);
int execute(stack_t **top, char *line, unsigned int Line_number, FILE *file);
void pint(stack_t **top, unsigned int Line_number);
void pop(stack_t **top, unsigned int Line_number);
void swap(stack_t **top, unsigned int Line_number);
int count_nodes(stack_t *top);
void add(stack_t **top, unsigned int Line_number);
void nop(stack_t **top, unsigned int Line_number);
void sub(stack_t **top, unsigned int Line_number);
void _div(stack_t **top, unsigned int Line_number);
void mul(stack_t **top, unsigned int Line_number);
#endif
