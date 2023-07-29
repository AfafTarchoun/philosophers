# Philosophers - Threading and Mutexes
:spaghetti: :book: 

## Summary

In this project, you will explore the basics of threading a process and learn about mutexes. You will simulate a scenario where philosophers sit at a round table, eating spaghetti and engaging in other activities like thinking and sleeping. Your task is to implement a program that handles the synchronization of these activities using threads and mutexes, ensuring that philosophers avoid starving and deadlocks.

## Overview

The simulation involves the following key points:

- One or more philosophers sit at a round table with a large bowl of spaghetti in the middle.
- Philosophers alternately eat, think, or sleep, and each action requires specific conditions to be met.
- There are as many forks on the table as there are philosophers.
- A philosopher takes their right and left forks to eat, holding one in each hand.
- The simulation stops when a philosopher dies of starvation, and the goal is to ensure that no philosopher starves.

## Global Rules

To ensure successful completion of the project, both the mandatory and bonus parts must follow these rules:

- Avoid using global variables in your program.
- Your program should take the following arguments:
  - `number_of_philosophers`: The number of philosophers and forks.
  - `time_to_die` (in milliseconds): The time limit for a philosopher to start eating after the last meal or the beginning of the simulation.
  - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat, requiring them to hold two forks during that period.
  - `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
  - `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when all philosophers have eaten this many times. Otherwise, it stops when a philosopher dies.
- Each philosopher is assigned a number from 1 to `number_of_philosophers`.
- Philosopher 1 sits next to philosopher `number_of_philosophers`, and any other philosopher N sits between philosopher N - 1 and philosopher N + 1.

## Logs and Display

- Log state changes of philosophers with timestamps, formatted as follows:
  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died
Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.
- Displayed state messages should not be mixed up with other messages.
- The announcement of a philosopher's death should be displayed no more than 10 ms after the actual death.
- Avoid data races in your program by properly protecting shared resources using mutexes.

## Mandatory Part

- Each philosopher should be represented as a thread.
- Place one fork between each pair of philosophers. If there are several philosophers, each one should have a fork on their left and a fork on their right. For a single philosopher, there should be only one fork on the table.
- Protect the state of forks with a mutex to prevent duplication.

## Compilation

To compile the "Philosophers" project, follow these steps:

. Clone the project repository to your local machine:

```bash
git clone https://github.com/AfafTarchoun/philosophers.git
cd philosophers
cd philo
make
```
## Usage
***for example***

```bash
./philo 5 800 200 400
```
## Output Interpretation
During the simulation, the program will display the activities of each philosopher with timestamps. The output will look like this:

```bash
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
- timestamp_in_ms: The current timestamp in milliseconds.
- X: The philosopher number.
  
**The simulation stops when a philosopher dies or when all philosophers have eaten the specified number of times (if provided).**
