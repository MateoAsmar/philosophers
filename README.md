# Philosophers  
## Grade: 100/100  
![philo](https://github.com/user-attachments/assets/98f09a22-48e3-4b5c-a254-ebaa0b388fc3)

## Overview

Philosophers is a multithreaded simulation of the classic Dining Philosophers problem. This project challenged me to master concurrent programming in C using pthreads, mutexes, and precise time management. It’s all about avoiding deadlocks, synchronizing threads, and managing resources effectively in a concurrent environment.

## Features

- **Multithreading:** Each philosopher is implemented as an individual thread.
- **Mutex Synchronization:** Uses mutexes to prevent race conditions and ensure safe access to shared resources (forks).
- **Time Management:** Leverages high-precision timing to simulate realistic thinking, eating, and sleeping behaviors.
- **Robust Error Handling:** Includes graceful error detection, resource cleanup, and proper mutex destruction.
- **42 Norm Compliance:** Written with clean, maintainable code following the strict 42 Norm.

## Project Details

- **Language:** C  
- **Compilation:** Compiled with `-Wall -Wextra -Werror`  
- **Norm Compliance:** Fully adheres to the 42 coding standards  
- **Testing:** Extensively tested under various timing configurations to ensure no deadlocks or race conditions occur

## Usage
***To compile philosophers:***

```bash
make
```

***To run philosophers:***
```bash
./philo nb_of_philosophers time_to_die time_to_eat time_to_sleep nb_of_times_each_philo_must_eat(optional)
```

## Files Structure

- **main.c**  
  The entry point of the program. It initializes the simulation environment, creates threads for each philosopher, and starts the simulation.

- **philo.h**  
  Contains structure definitions, function prototypes, and macros used across the project.

- **check.c**  
  Monitors philosopher status, checking for death conditions and ensuring proper synchronization.

- **init.c**  
  Initializes philosopher structures, mutexes, and threads; sets initial simulation parameters.

- **philo_utils.c**  
  Utility functions for managing philosopher threads, including joining threads and managing the eating count.

- **time.c**  
  Provides functions to retrieve the current time in milliseconds and to manage simulation timing.

- **utils.c**  
  Contains helper functions (e.g., custom `ft_atoi`) and other utilities used throughout the project.

## What I Learned

Working on the Philosophers project was an incredible journey into the world of concurrent programming:

- **Multithreading Mastery:** I gained hands-on experience with pthreads and learned how to manage multiple threads while avoiding deadlocks.
- **Precise Time Management:** Implementing timing functions deepened my understanding of how to simulate real-world delays and actions.
- **Synchronization Techniques:** The project reinforced best practices for safely sharing resources using mutexes.
- **Clean Code Practices:** Adhering to the 42 Norm improved my ability to write clean, maintainable, and robust code.

## Conclusion

Philosophers pushed me to solve real-world challenges in concurrency and synchronization. This project not only honed my technical skills in C but also deepened my understanding of multithreaded programming complexities. It’s a rewarding project that reflects my passion for writing clean, efficient, and reliable code. 💡🔥
