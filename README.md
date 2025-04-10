# Veterinary Management System (VMS)

## Overview

The **Veterinary Management System (VMS)** is a C++ console application designed to manage information related to pets, pet owners, and appointments in a veterinary clinic. This system allows users to add pets, add owners, schedule appointments, view appointments, and save/load data from files for persistence.

## Features

- **Pet Management**:  
  - Add and manage pets (name, breed, age, and vaccination status).
  - Save pet information to a file.
  
- **Owner Management**:  
  - Add and manage pet owners (name, address, phone number, and email).
  - Save owner information to a file.

- **Appointment Management**:  
  - Schedule appointments for pets with their respective owners.
  - View, complete, or cancel appointments.
  - Save appointment data to a file.

- **Input Validation**:  
  - Ensures valid numeric input for pet age and vaccination status.
  - Prevents scheduling appointments for dates earlier than today.

## Requirements

- **C++ Compiler** (e.g., GCC, Clang, Visual Studio)
- **Operating System**: This project can run on Windows, Linux, or macOS.

## Installation

1. **Clone the Repository**  
   Clone the repository to your local machine using the following command:
   ```bash
   git clone https://github.com/your-username/veterinary-management-system.git
