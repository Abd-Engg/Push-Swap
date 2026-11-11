*This activity has been created as part of the 42 curriculum by nalrjoub, abmalkaw.*

# Push Swap

## Description
Push Swap is a program which sorts a stack of integers (stack A) with the help of another stack (stack B) and a limited set of instructions.
The program implements three different sorting strategies which could be determined using flags as input, otherwise the program will choose one of the three strategies based on the disorder of the input.

### Operations
Allowed operations are as follows:

| symbol | operation |
|--------|-----------|
|pa      |Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty|
|pb      |Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty|
|sa      |Swap the first two elements at the top of `stack a`. Do nothing if there is only one or no elements|
|sb      |Swap the first two elements at the top of `stack b`. Do nothing if there is only one or no elements|
|ss      |`sa` and `sb` at the same time|
|ra      |Shift up all elements of `stack a` by one. The first element becomes the last one|
|rb      |Shift up all elements of `stack b` by one. The first element becomes the last one|
|rr      |`ra` and `rb` at the same time|
|rra     |Shift down all elements of `stack a` by one. The last element becomes the first one|
|rrb     |Shift down all elements of `stack b` by one. The last element becomes the first one|
|rrr     |`rra` and `rrb` at the same time|

### Strategies
| Strategy | Flag | Complexity (in number of operations) |
|----------|------|---------------------------------------|
| Simple   | `--simple`   | O(n²)    |
| Medium   | `--medium`   | O(n√n)   |
| Complex  | `--complex`  | O(n log n) |
| Adaptive | `--adaptive` (default) | depends on disorder (see below) |

### Disorder
Disorder is a value in `[0, 1]` measuring how far the initial stack `a` is from sorted. It is the ratio of **inversions** (pairs `i < j` with `a[i] > a[j]`) to the **total number of pairs** `n(n-1)/2`.
- `0`: already sorted
- `1`: sorted in exact reverse order
This metric is used when no flag is set for the sorting strategy, and when the `benchmark` flag is set, as the disorder is displayed as a percentage with two decimals.

## Instructions
 
### Compilation
 
```bash
make        # builds ./push_swap
make clean  # removes object files
make fclean # removes objects and the binary
make re     # fclean + all
```

### Execution
 
```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <int> <int> ...
```
keep in mind that the strategy selection flag and the bench flag are interchangable. 
 
### Usage examples
 
```bash
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_os $ARG
OK
$> ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_os $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
$> ./push_swap --adaptive 0 one 2 3
Error
```

## Project Structure
```
Push-Swap
│   main.c
│   Makefile
│   README.md
│   
├───algorithms
│       complex.c
│       medium.c
│       simple.c
│       
├───header_files
│       ft_printf.h
│       libft.h
│       pushswap.h
│       
├───imports
│   ├───libft
│   │       ft_atoi.c
│   │       ft_isalpha.c
│   │       ft_isdigit.c
│   │       ft_itoa.c
│   │       ft_split.c
│   │       ft_strcmp.c
│   │       ft_strjoin.c
│   │       ft_strlcpy.c
│   │       ft_strlen.c
│   │       
│   └───printf
│           ft_printf.c
│           ft_putchar.c
│           ft_putfloat.c
│           ft_puthexa.c
│           ft_putnbr.c
│           ft_putptr.c
│           ft_putstr.c
│           ft_putunsigned.c
│           
├───operations
│       ops_a.c
│       ops_b.c
│       ops_both.c
│       stack_ops.c
│       
└───utilities
    │   disorder.c
    │   print_benchmark.c
    │   sort_args.c
    │   stack.c
    │   
    └───parsing
            checking.c
            parsing.c
            Set_Data.c
```

## Resources
- [doubly linked list] https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
- [merge sort] https://www.geeksforgeeks.org/dsa/merge-sort/
- [radix sort] https://www.geeksforgeeks.org/dsa/radix-sort/
- [radix sort] https://brilliant.org/wiki/radix-sort/
- [counting sort] https://brilliant.org/wiki/counting-sort/