/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 17:46:38 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

/*
	The selector is going to be found within the argv.
	If selector is given, strategy is going to be equal to it.
	If no selector is given it defaults to adaptive, which then
	selects a strategy (can only be simple, medium, or complex).
*/
typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
	char		*strategy_arg;
	char		*strategy;
	char		*strategy_complexity;
	double		disorder;
	t_benchmark	*bench;
}	t_stack;

typedef struct s_benchmark
{
	int		ops_count;
	int		pa_count;
	int		pb_count;
	int		sa_count;
	int		sb_count;
	int		ra_count;
	int		rb_count;
	int		rra_count;
	int		rrb_count;
	int		rr_count;
	int		ss_count;
	int		rrr_count;
}	t_benchmark;

typedef struct s_node
{
	long			value;
	long			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//STACK UTILS
void		ft_stackinit(t_stack **stack, int argc, char **argv);
t_stack		*ft_stacknew(void);
t_node		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_node *new);
int			ft_stacksize(t_stack *stack);
void		ft_free_stack(t_stack **stack);
int			ft_stacksorted(t_stack *stack);

//SORTING
void		ft_sort_method(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_three(t_stack **stack);

//PUSHSWAP STRUCT
void		ft_parse_pushswap(t_stack **a, t_stack **b, int argc, char **argv);

//UTILS
void		ft_exit(int error);
void		ft_printstack(t_stack *stack);
int			ft_strcmp(char *s1, char *s2);
float		ft_compute_disorder(int *numbers, int size);

//STACK UTILS
t_node		*ft_node_new(int value, int index);
t_stack		*ft_parse_stack(int *numbers, int numbers_size);
int			ft_stacksize(t_stack *stack);
void		ft_free_stack(t_stack **stack);
void		ft_stackindex(t_stack *stack);
int			ft_issorted(int *numbers, int size);
int			ft_index(t_stack *stack, int target);
int			ft_indexrel(t_stack *stack, int target);
void		ft_printstack(t_stack *stack);

//BENCH_UTILS
void		ft_print_bench(t_stack *stack);

//PARSE UTILS
int			ft_isspace(char c);
int			ft_isspace_str(const char *str);
int			ft_valid_int(char *nbrstr);
int			ft_int_range(long n);
char		*ft_strjoin_sep(char *prev, char *new);
int			ft_find_bench(int argc, char **argv);
int			ft_valid_selector(char *str);
int			ft_duplicated(int *arr, int size);

//OPERATIONS
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_sa(t_stack *a);
void		ft_sb(t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);
void		ft_push(t_stack *dest, t_stack *src);
void		ft_swap(t_stack *stack);
void		ft_rotate(t_stack *stack);
void		ft_reverse(t_stack *stack);

#endif