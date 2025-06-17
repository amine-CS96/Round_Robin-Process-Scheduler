
# Round-Robin Process Scheduler — Console-Based Process Management in C

This C program is a command-line application for simulating process scheduling using the **Round-Robin (RR)** algorithm. It allows users to add processes, execute them with a time quantum, manage the passage of time, and monitor the current state of the queue. The data is managed in memory using a **circular doubly-linked list** and structured in a modular fashion.

---

## Features

* Add a new process with a unique ID, arrival time, and execution duration.
* Schedule and execute processes using the Round-Robin algorithm.
* Execute all remaining processes until the queue becomes empty.
* Display the current state of the queue with all active processes.
* Validate process IDs (uniqueness) and ensure increasing arrival times.
* Interactive console-based menu for managing processes.
* Modular code with separate source and header files.

---

## Project Structure

```
RoundRobin-Scheduler-C/
├── include/
│   └── process.h                 # Header file with data structures and function prototypes
├── src/
│   └── process.c                 # Core implementation of process scheduling logic
├── main.c                        # Main program with interactive menu and user input handling
└── README.md                     # This documentation file
```

---

## How to Compile

From the project root directory, compile the code using:

```bash
gcc main.c src/process.c -o scheduler
```

---

## How to Run

After compilation, launch the program:

```bash
./scheduler
```

---

## Display Menu

Upon launching, the following menu will appear:

```
------------------------------ MENU :--------------------------------------------------------
1.  Add a process to the queue.

2.  Execute a process for a time quantum.

3.  Display the current state of the queue.

4.  Manage the passage of time.

5.  Exit.
--------------------------------------------------------------------------------------------
```

Follow the prompts to add, execute, or manage processes.

---

## Example Queue Display

```
---------------------------------< Queue State: >-----------------------------------
====> Process with PID = ( 101 )
---> Position : (0x564b3c41)
---> Arrival Time : ( 3 )
---> Remaining Time : ( 7 )

====> Process with PID = ( 102 )
---> Position : (0x564b3c89)
---> Arrival Time : ( 6 )
---> Remaining Time : ( 5 )

------------------------------------------------------------------------------------
```

---

## Highlights & Learning Outcomes

* Practice with **dynamic memory allocation** and **linked data structures**.
* Simulation of **process scheduling** using Round-Robin logic.
* Understanding of **circular doubly-linked lists** and traversal techniques.
* Real-time **menu-based interaction** and state updates.
* Strong separation of concerns using header and source files.

---

## Limitations & Future Improvements

* Add persistent file saving/loading of process queues.
* Add timestamps and statistics (e.g., turnaround time, waiting time).
* Improve error handling and edge case validation.
* Visualize the scheduler with a simple GUI or terminal animation.
* Add priority-based scheduling as an optional mode.

---

## License


This project is licensed under the MIT License — you are free to use, copy, modify, merge, publish, and distribute the software, provided that the original author is credited and the license notice is included in all copies or substantial portions of the software.

See the [LICENSE](LICENSE) file for full terms.

---

