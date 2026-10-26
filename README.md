_This project has been created as part of the 42 curriculum by darmarti._

# philosophers

## Description

`philosophers` is a concurrent simulation of the dining philosophers problem.
Each philosopher runs in its own POSIX thread and must repeatedly take forks,
eat, sleep, and think. A monitor detects deaths and stops the simulation when
the configured meal goal has been reached.

The project focuses on thread creation, mutexes, timing, synchronization, and
avoiding data races and deadlocks.

## Requirements

- Unix-like operating system
- C compiler
- `make`
- POSIX threads
- Valgrind (optional, for race and leak checks)

## Build and run

```sh
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
    [number_of_times_each_philosopher_must_eat]
```

All time values are expressed in milliseconds. The optional final argument
ends the simulation after every philosopher has eaten that many times.

Example:

```sh
./philo 5 800 200 200
./philo 5 800 200 200 3
```

The program prints timestamped actions such as taking a fork, eating, sleeping,
thinking, and dying.

Useful Make targets:

```sh
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
make norme    # Run Norminette checks
make leaks    # Run configured Valgrind checks
make run      # Run the configured scenarios
```

## Project structure

- `srcs/initialization.c`: argument validation and simulation setup
- `srcs/philo_routines.c`: philosopher thread routines
- `srcs/monitor_utils.c`: monitoring and simulation termination
- `srcs/safe_handlers.c`: checked thread and mutex operations
- `srcs/utils.c`: timing, parsing, and thread joining
- `srcs/handle_errors.c`: error reporting

## Resources

- [POSIX Threads](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html)
- `pthread_create(3)`, `pthread_mutex_lock(3)`, and `gettimeofday(2)`
- [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
