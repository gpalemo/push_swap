![C](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)
![Sorting algorithm](https://img.shields.io/badge/algorithm-radix_sort-green)


# PUSH_SWAP

*This project has been created as part of the 42 curriculum by cmauley.*

---

## Description

**push_swap** is a sorting project where the goal is to sort a list of integers using a very limited set of operations and two stacks.

The program receives a sequence of integers as arguments, stores them in stack **A**, and must output the shortest possible list of instructions to sort them in ascending order.
A second stack (**B**) can be used as temporary storage.

The challenge is not only to sort the numbers, but to do it using the **minimum number
of operations**.

### Benchmark

To validate this project, you must perform certain sorts with a minimal number of oper-
ations:
- For maximum project validation (100%) and eligibility for bonuses, you must:
	- Sort 100 random numbers in fewer than 700 operations.
	- Sort 500 random numbers in no more than 5500 operations.
- For minimal project validation (which implies a minimum grade of 80%), you
	can succeed with different averages:
	- 100 numbers in under 1100 operations and 500 numbers in under
	8500 operations
	- 100 numbers in under 700 operations and 500 numbers in under
	11500 operations
	- 100 numbers in under 1300 operations and 500 numbers in under
	5500 operations

**Allowed operations include:**

- sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
- rrr : rra and rrb at the same time

---

### Instructions

In **BASH** :
<pre> make ./push_swap 3 2 1 </pre>

 or with quotes

 <pre> make ./push_swap "3 2 1" </pre>

 *A checker is also provided in order to properly check the program. To run it do :*

  <pre> ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
</pre>

*with number of operations :*

<pre> ./push_swap $ARG | wc -l </pre>

### Features

- Parsing and validation of input
- Error management (duplicates, invalid numbers, overflow)
- Sorting of small stacks with optimal solutions
- Efficient sorting for large datasets using radix sort
- Memory leak free


# Algorithm

## Small stacks (<= 5 numbers)

For small inputs, the program uses manually defined optimal sorting sequences.

- 2 numbers → swap if needed

- 3 numbers → minimal combination of swap / rotate / reverse rotate

- 4 and 5 numbers → push the smallest elements to stack B, sort the remaining
elements, then push them back to stack A

This guarantees the lowest possible number of operations for small datasets.

## Radix Sort

### Why I chose Radix Sort

For the sorting part of this project, I decided to implement a radix sort–based algorithm.

My main goal was not to pick the most optimized solution possible, but to choose an algorithm that is:

- easy to understand

- structured

- and a good introduction to algorithmic thinking

Radix sort is often recommended for push_swap because it allows you to reach the required performance without implementing a very complex cost-calculation system.
For someone who is still learning how sorting algorithms work, it is a very good way to:

- understand how to break a problem into steps

- manipulate stacks in a systematic way

- work with binary representations

- build a full algorithm from scratch

So in this project, radix sort was a learning choice before being an optimization choice.

### Complexity and limitations

Even if radix sort performs well for the evaluation benchmarks, it is not the most efficient algorithm for push_swap in terms of number of operations.

The time complexity of radix sort is:

<pre>
O(n × k)
</pre>

Where:

- **k** = number of bits needed to represent the biggest index

- In this project, since we normalize the values into indexes from **0** to **n - 1**,
**k** is roughly **log₂(n)**.

So the real complexity becomes:

<pre>
O(n log n)
</pre>

This is good, but not optimal for push_swap in terms of instruction count.

More advanced algorithms based on:

- cost calculation

- greedy insertion

- chunking strategies

can produce **significantly fewer operations**, especially for large inputs.

That means:

**radix sort is efficient enough to validate the project, but it is not the fastest possible solution. For example, with my code, for 100 random numbers it makes 1084 actions and for 500, 6784 actions. Which is clearly not the best, but enough to validate the project.**

### Indexing

Before applying radix sort, each number is replaced by its index in the sorted list.

Example:

<pre>
Values:        42   5   100
Sorted:        5   42   100
Indexes:       1    0    2
</pre>

This allows the algorithm to work only with positive numbers starting from 0,
which makes bitwise operations possible and simplifies the sorting process.

## Bigger stacks (> 5 numbers)

For large inputs, the program uses a **binary radix sort adapted to stacks**.

The algorithm processes numbers bit by bit, starting from the least significant bit.

For each bit position:

1. Check the value of the current bit of the top element in stack A

2. If the bit is **0 → push the element to stack B**

3. If the bit is **1 → rotate stack A**

4. Repeat for all elements in stack A

5. Push everything back from stack B to stack A

Each pass partially sorts the numbers.
After processing all bits, the stack is completely sorted.

### Error Handling

The program outputs:

<pre> Error\n </pre>

to stderr in the following cases:

- non-numeric arguments

- integer overflow or underflow

- duplicate values

- invalid input

- If no arguments are provided, the program prints nothing.

- If the list is already sorted, the program prints nothing.

## Resources

- Radix sort : https://en.wikipedia.org/wiki/Radix_sort

- Bitwise operations in C : https://www.w3schools.com/c/c_bitwise_operators.php

- The readme from a 42 student "Cyglardo" : https://github.com/Jayleeva/42push_swap

- This checker : https://github.com/gemartin99/Push-Swap-Tester

- This guide for push swap : https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/building-the-thing

- To verify memory leaks : https://valgrind.org/docs/manual/quick-start.html

### IA usage

AI was used as a learning support tool for:

- a better understanding of radix sort

- and to improve algorithm clarity

**All code logic, implementation, and debugging were done manually.**
