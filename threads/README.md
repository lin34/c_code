# using valgrind/helgrind to detect race conditions in race_condition.c

gcc -g -pthread race_condition.c -o race_test

valgrind --tool=helgrind ./race_test

## output

==7625== ----------------------------------------------------------------
==7625==
==7625== Possible data race during read of size 4 at 0x10C014 by thread #3
==7625== Locks held: none
==7625== at 0x1091BE: count_to_big (race_condition.c:12)
==7625== by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==7625== by 0x48FDAC2: start_thread (pthread_create.c:442)
==7625== by 0x498EA03: clone (clone.S:100)
==7625==
==7625== This conflicts with a previous write of size 4 by thread #2
==7625== Locks held: none
==7625== at 0x1091C7: count_to_big (race_condition.c:12)
==7625== by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==7625== by 0x48FDAC2: start_thread (pthread_create.c:442)
==7625== by 0x498EA03: clone (clone.S:100)
==7625== Address 0x10c014 is 0 bytes inside data symbol "counter"
==7625==
==7625== ----------------------------------------------------------------
==7625==
==7625== Possible data race during write of size 4 at 0x10C014 by thread #3
==7625== Locks held: none
==7625== at 0x1091C7: count_to_big (race_condition.c:12)
==7625== by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==7625== by 0x48FDAC2: start_thread (pthread_create.c:442)
==7625== by 0x498EA03: clone (clone.S:100)
==7625==
==7625== This conflicts with a previous write of size 4 by thread #2
==7625== Locks held: none
==7625== at 0x1091C7: count_to_big (race_condition.c:12)
==7625== by 0x485396A: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-amd64-linux.so)
==7625== by 0x48FDAC2: start_thread (pthread_create.c:442)
==7625== by 0x498EA03: clone (clone.S:100)
==7625== Address 0x10c014 is 0 bytes inside data symbol "counter"
==7625==
Done. Counter 2000000000
==7625==
==7625== Use --history-level=approx or =none to gain increased speed, at
==7625== the cost of reduced accuracy of conflicting-access information
==7625== For lists of detected and suppressed errors, rerun with: -s
==7625== ERROR SUMMARY: 150 errors from 2 contexts (suppressed: 0 from 0)

# Using mutexes to fix the race condition in race_condition_sol.c

gcc -g -pthread race_condition_sol.c -o race_test_sol

valgrind --tool=helgrind ./race_test_sol

## output

==10952== Helgrind, a thread error detector
==10952== Copyright (C) 2007-2017, and GNU GPL'd, by OpenWorks LLP et al.
==10952== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10952== Command: ./race_test_sol
==10952==
Done. Counter 2000000
==10952==
==10952== Use --history-level=approx or =none to gain increased speed, at
==10952== the cost of reduced accuracy of conflicting-access information
==10952== For lists of detected and suppressed errors, rerun with: -s
==10952== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 3000004 from 7)
