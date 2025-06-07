# How to use valgrind/helgrind to detect race conditions in race_condition.c

gcc -g -pthread race_condition.c -o race_test

valgrind --tool=helgrind ./race_test

## Solution using mutexes: race_condition_sol.c

gcc -g -pthread race_condition_sol.c -o race_test_sol

valgrind --tool=helgrind ./race_test_sol

## using gcc to debug a threaded application:

- set breadpoints at the beginning of the thread function

Set breakpoints,
b <line number>
break <function>

- e.g. break count_to_big

next

- setting a watch point for a variable
- useful if you want to stop when a var equals a certain value
  watch counter >= 9

info threads

- Each thread is given a thread id
  LWP: Light Weight Process

- Can change which thread you are looking at by using:
  thread <thread id name>

thread apply all
