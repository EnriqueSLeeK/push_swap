# Push swap

It's a simple algorithm project
Our objective is to sort a stack named `a` using the least amount of operations from a limited set of actions available and one auxiliary stack named `b`

## Operation
| Name | Description |
|---|---|
| sa | swap the first 2 number at hte top of a |
| sb | swap the first 2 number at hte top of b |
| ss | do sa and sb at the same time |
| pa | take the top element at b and place it to the top of a |
| pb | take the top element at a and place it to the top of b |
| ra | shift up all elements of stack a by 1 |
| rb | shift up all elements of stack b by 1 |
| rr | do ra and rb at the same time |
| rra | shift down all elements of stack a by 1 |
| rrb | shift down all elements of stack b by 1 |
| rrr |do rra and rrb at the same time |

## How to compile
```
make
```
## Usage
```
./push_swap n_1 n_2 n_3 ... n_n
```
- It will not accept argument with mixed format such as `n_1 n_2 "n_3 n_4" n_5`

# Checker

This program will check if the operations done by the program `push_swap` sorted the stack `a` and will see if the stack `b` it's empty.
- This program read from the stdin

## How to compile
```
make bonus
```
## Usage
```
./push_swap n_1 n_2 n_3 ... n_n | ./checker n_1 n_2 n_3 ... n_n
```
- The checker program must receive the same arguments given to `push_swap`
Or
```
./checker n_1 n_2 n_3 ... n_n
op_1
op_2
```
- Press `CTRL + d` to stop reading
- It will not accept argument with mixed format such as `n_1 n_2 "n_3 n_4" n_5`

## For more information
Please check the `subject.pdf`
