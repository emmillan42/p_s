/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "push_swap.h"

float ft_compute_disorder(int *numbers, int size)
{
    int mistakes;
    int total_pairs;
    int i;
    int j;

    i = -1;
    mistakes = 0;
    total_pairs = 0;
    while (++i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (numbers[i] > numbers[j])
                mistakes++;
            total_pairs++;
            j++;
        }
    }
}

int ft_stacksize(t_stack *a)
{
	return (3);
}

float compute_disorder(t_stack *stack)
{
    int mistakes;
    int total_pairs;
    int i;
    int j;
    int size;

    size = ft_stacksize(stack);
    i = -1;
    mistakes = 0;
    total_pairs = 0;
    while (++i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (stack->value > (stack->next)->value)
                mistakes++;
            total_pairs++;
            j++;
        }
    }
}

int main()
{
    char str[] = "a";
    char se1[] = "--simple";
    char se2[] = "--medium";
    char se3[] = "--complex";
    char se4[] = "--adaptive";
    int		arr[] = {3, 2, 1, 5, 97, 43, 6, 7, 42, 8};
    printf("Hello World %.2f\n", ft_compute_disorder(arr, (sizeof(arr) / sizeof(int))));
    printf("Hello World %d\n", strcmp(str, se1));

    return 0;
}
