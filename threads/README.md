# How to use valgrind/helgrind to detect race conditions in race_condition.c

gcc -g -pthread race_condition.c -o race_test

valgrind --tool=helgrind ./race_test

## Solution using mutexes: race_condition_sol.c

gcc -g -pthread race_condition_sol.c -o race_test_sol

valgrind --tool=helgrind ./race_test_sol
