#include "../includes/push_swap.h"

int get_chunk_size(t_list *stack, int chunk)
{
    int len;

    len = 0;
    while (stack && stack->chunk == chunk)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

int get_count_of_created_chunks(int chunk_size, int chunk_number)
{
	int chunk_count;

	chunk_count = 0;
	if (chunk_number == 0)
		while (chunk_size >= 2)
		{
			chunk_count++;
			chunk_size /= 2;
		}
	else
		while (chunk_size > 0)
		{
			chunk_count++;
			chunk_size /= 2;
		}
	return chunk_count;
}

void pull_whole_chunk_to_a(t_list **a_stack, t_list **b_stack, int chunk)
{
	while (*b_stack && (*b_stack)->chunk == chunk)
	{
		push_a(a_stack, b_stack);
		*b_stack = (*b_stack)->next;
	}
}

bool is_stack_already_sorted(t_list *stack)
{
	int current_number;
	int next_number;

	while (stack->next)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number > next_number)
			return false;
		stack = stack->next;
	}
	return true;
}

bool is_chunk_already_sorted_asc(t_list *stack, int chunk)
{
	int current_number;
	int next_number;

	while (stack->next && stack->chunk == chunk && stack->next->chunk == chunk)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number > next_number)
			return false;
		stack = stack->next;
	}
	return true;
}

bool is_chunk_already_sorted_desc(t_list *stack, int chunk)
{
	int current_number;
	int next_number;

	while (stack->next && stack->chunk == chunk && stack->next->chunk == chunk)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number < next_number)
			return false;
		stack = stack->next;
	}
	return true;
}

void insert_chunk_number(t_list **stack, int chunk)
{
	t_list *iterator;

	iterator = (*stack);
	while (iterator)
	{
		iterator->chunk = chunk;
		iterator = iterator->next;
	}
}

void insert_chunk_number_len(t_list **stack, int chunk, int len)
{
    t_list *iterator;

    iterator = (*stack);
    while (iterator && len)
    {
        iterator->chunk = chunk;
        iterator = iterator->next;
        len--;
    }
}

static void solve_two(t_list **a_stack)
{
	int first;
	int second;

	first = *(int *) (*a_stack)->content;
	second = *(int *) (*a_stack)->next->content;

	if (first > second)
		swap_a(a_stack);
}

static void solve_three(t_list **a_stack)
{
	int first;
	int second;
	int third;

	first = *(int *) (*a_stack)->content;
	second = *(int *) (*a_stack)->next->content;
	third = *(int *) (*a_stack)->next->next->content;

	if (first < second && second < third)
		return;
	else if (first > second && second < third && first < third)
		swap_a(a_stack);
	else if (first > second && first > third && second < third)
		rotate_a(a_stack);
	else if (first < second && first > third && second > third)
		reverse_rotate_a(a_stack);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(a_stack);
		swap_a(a_stack);
	} else if (first > second && second > third)
	{
		rotate_a(a_stack);
		swap_a(a_stack);
	}
}

static void serious_solve(t_list **a_stack, t_list **b_stack)
{
    int current_chunk;
    int total_chunk_number;

    current_chunk = 0;
	total_chunk_number = 0;
    insert_chunk_number(a_stack, total_chunk_number);
    while (!is_stack_already_sorted(*a_stack))
    {
		if (total_chunk_number == 0)
			current_chunk = total_chunk_number;
		else
			current_chunk = (total_chunk_number - 1);
        while (current_chunk >= 0)
        {
			print_chunk(*a_stack, current_chunk); // TODO
            pull_chunk_to_b(a_stack, b_stack, &current_chunk, total_chunk_number);
            total_chunk_number++;
        }
		total_chunk_number--;
        current_chunk = (total_chunk_number - 1);
        while (current_chunk >= 0)
        {
			print_chunk(*b_stack, current_chunk); // TODO
            pull_chunk_to_a(a_stack, b_stack, &current_chunk, total_chunk_number);
            total_chunk_number++;
        }
    }
}

void solve(t_list **a_stack, t_list **b_stack)
{
	int a_stack_size;

	a_stack_size = ft_lstsize(*a_stack);
	if (a_stack_size == 1 || is_stack_already_sorted(*a_stack))
		return;
	else if (a_stack_size == 2)
		solve_two(a_stack);
	else if (a_stack_size == 3)
		solve_three(a_stack);
	else
		serious_solve(a_stack, b_stack);
}
