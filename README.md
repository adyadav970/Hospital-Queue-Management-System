# Hospital Queue Management System

## Project Description

The Hospital Queue Management System is a console-based application
developed in C++ for managing normal and emergency patients in an
organized manner.

The system maintains a normal patient queue and an emergency priority
queue. Normal patients are served according to the FIFO principle,
while emergency patients are served according to their assigned
priority.

## Features

- Add Normal Patient
- Add Emergency Patient
- Automatic Patient ID Generation
- Emergency Priority Management
- Serve Next Patient
- View Normal Queue
- View Emergency Queue
- Search Patient by ID
- Search Patient by Name
- Input Validation
- Empty Queue Handling

## Data Structures Used

- Queue
- Priority Queue
- Vector
- Structure

## Priority Levels

1. High
2. Medium
3. Low

## Technologies Used

- C++
- C++ Standard Template Library (STL)

## How the System Works

Normal patients are stored in a FIFO queue.

Emergency patients are stored in a priority queue. The priority
levels are:

- High
- Medium
- Low

When serving the next patient, emergency patients are served first.
If there are no emergency patients, the next normal patient is served.

## Patient ID

Patient IDs are generated automatically.

The first patient receives ID `1001`, and the ID is increased
automatically for every new patient.

## How to Run

1. Download or clone this repository.
2. Open the C++ source file in a C++ compiler or IDE.
3. Compile the program.
4. Run the executable.
5. Use the menu to manage patients.

## Project Structure

```text
Hospital-Queue-Management-System/
│
├── Hospital_Queue_Management_System.cpp
└── README.md
