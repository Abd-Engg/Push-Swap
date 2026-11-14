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
- `1`: sorted in exact reverse order\
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

## Algorithm
Before any strategy runs, every value is replaced by its rank in the sorted input (the smallest number becomes 0, the largest becomes n-1). All three algorithms below rely on this.

### 1. Simple: selection sort, O(n²)
This algorithm repeatedly searches for the smallest element in `stack A`, and puts it in `stack B`. Which results in `stack B`, which results in sorting `stack B` in descending order.\
Then, starting from the head of `stack B`, each number is pushed onto `stack B`, which basically results in `stack A` having the reverse order of `stack B`, which is ascending order (starting from `head`).

```
target = 0
while a is not empty:
    index = position of target in a
    bring that element to the top of a   (shortest rotation)
    pb                                   (push it onto b)
    target++
while b is not empty:
    pa
```

### 2. Medium: chunk-based sort, O(n√n)

Split the ranks into chunks of size c = ⌊√n⌋. Move the chunks from `stack A` to `stack B` one after another, so that `b` becomes almost sorted by chunk. Then pull the elements back in descending order, which is cheap because the next maximum is always close to the top of `b`.\
**Stack B after stage A:** Chunk `[0..c-1]` was pushed first, chunk `[c..2c-1]` next, and so on, so `b` contains the chunks stacked from lowest (bottom) to highest (top). Inside a chunk the elements are in arbitrary order. For `n = 9` (`c = 3`): top of `b` holds ranks from `{6,7,8}`, then `{3,4,5}`, then `{0,1,2}` underneath. If `n` is not a perfect square, the last chunk is simply smaller (the inner loop also stops when `a` is empty).

```
c = floor(sqrt(n))
start = 0
# Stage A: a -> b, chunk by chunk
while a is not empty:
    moved = 0
    while moved < c and a is not empty:
        if start <= top(a) < start + c:
            pb; moved++
        else:
            ra
    start += c
 
# Stage B: b -> a, largest first
for target = n-1 down to 0:
    bring target to the top of b   (shortest rotation: rb or rrb)
    pa
```

### 3. Complex: LSD radix sort, O(n log n)

**LSD radix sort on base 2** for each element (the rank of each element in our case).\
The big picture of the algorithm is that fpr each bit, from the lowest to the highest (from LSB to MSB). elements whose but is `0` go to `stack B`, elements whose bit is `1` stay in `a`. Then bring everything back to `a`.

The total number of iterations in this algorithm is `log2(n - 1)`, which is the number of bits needed to represent the largest element in our stack.

Each iteration represents the position of the bit we need to check, so right shift is performed on the element (`number >> i`), where `i` represents the current iteration number.

During each iteration, each `ra` sends a `1` element to the bottom in the order it was seen, so the `1` elements keep their relative order. The `0` elements are pushed onto `b` in the order they were seen, which reverses them; the `pa` loop reverses them again, so they land back on top of a in their original relative order, in front of the `1` elements.

After each iteration `i`, `a` is ordered by bit `i` (zeros starting from head), with ties kept in the order of the previous iteration. After the last bit (the most significant one), `a` is sorted in ascending order.

```
bits = number of bits of (n-1)
for i = 0 to bits-1:
    repeat n times:
        if bit i of top(a) is 0:  pb
        else:                     ra
    while b is not empty:
        pa
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

## Team contribution
| Learner | Login | Contributions |
|---------|-------|---------------|
| abd | abmalkaw | parsing & error handling, simple + medium strategies, makefile |
| nagham | nalrjoub | stack implementation & operations, disorder, complex strategy, README file |

No part of the code was done without being reviewd by both learners. Both learners understand all of the code.

## Resources
- [doubly linked list] https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
- [merge sort] https://www.geeksforgeeks.org/dsa/merge-sort/
- [radix sort] https://www.geeksforgeeks.org/dsa/radix-sort/
- [radix sort] https://brilliant.org/wiki/radix-sort/
- [counting sort] https://brilliant.org/wiki/counting-sort/

## AI usage
- AI was used to help write this README file
- AI was used to help with norm
