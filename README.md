# push_swap

#### ./push_swap
The goal of this program is to create a list of instructions (as short as possible) that will sort a set of numbers given as a string. Only two stacks of memory were allowed to complete this project.

#### ./checker
The checker program will take the string of numbers and the list of instructions as arguments and will return either OK or KO to signify if the list has been successfully sorted.

----
### Instructions
|    |                                                                                                         |
|----|---------------------------------------------------------------------------------------------------------|
|sa  |swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.|
|sb  |swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.|
|ss  |sa and sb at the same time.                                                                              |
|pa  |push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.    |
|pb  |push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.    |
|ra  |rotate a - shift up all elements of stack a by 1. The first element becomes the last one.                |
|rb  |rotate b - shift up all elements of stack b by 1. The first element becomes the last one.                |
|rr  |ra and rb at the same time.                                                                              |
|rra |reverse rotate a - Shift down all elements of stack a by 1. The first element becomes the last one.      |
|rrb |reverse rotate b - Shift down all elements of stack b by 1. The first element becomes the last one.      |
|rrr |rra and rrb at the same time.                                                                            |

----
### Installation
```bash
git clone https://github.com/AuroraSloan/push_swap.git
```
----
## Usage
First, create the executables with make
```bash
make - compiles the push_swap and checker executables
make clean - removes all .o files
make fclean - removes all .o files and the executables
make re - removes all .o files and all executables before recompiling the programs
```

#### push_swap
Run the push_swap program with a list of integers, and the instruction list will be printed
```bash
./push_swap 6 3 2 0 9
```
#### checker
Run the checker program with a list of integers. After pressing enter, the program will wait for instructions. Type the instructions one by one and press enter in between each. OK or KO will be printed based on whether you provided the correct instructions. In order to notify the program that you are finished inputting instruction, type crtl+d.
```bash
./checker 6 3 2 0 9
rra
rra
pb
rra
pb
sa
rra
pa
pa
```

The two programs can be used together and the checker program will check the push_swap program. The output should always be OK as long as the numbers input are valid and not duplicates.
```bash
./push_swap 6 3 2 0 9 | ./checker 6 3 2 0 9
```
or
```bash
ARG="6 3 2 0 9";./push_swap $ARG | ./checker $ARG
```

An Error will be displayed in case of a number that is larger than INT_MAX or smaller than INT_MIN or if there is a duplicate number.
