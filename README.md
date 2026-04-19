# 🚗 Rush Hour Puzzle Game

## Overview

This project is a simplified implementation of the classic Rush Hour puzzle game written in C++. The objective of the game is to move vehicles on a grid in order to clear a path for the target car to reach the exit.

The project was developed to strengthen my understanding of object-oriented programming, 2D arrays, and logical problem-solving in C++.

---

## Features

- Grid-based game board (6x6 layout)
- Multiple vehicles with fixed movement directions (horizontal or vertical)
- User-controlled movement through console input
- Move validation to prevent illegal moves and collisions
- Real-time board updates after each move
- Win condition detection when the target vehicle reaches the exit

---

## How the Game Works

The game starts with a predefined board setup containing different vehicles placed in specific positions. Each vehicle can only move in one direction depending on its orientation.

The player enters commands to move vehicles step by step. After each move, the program checks whether the move is valid and updates the board accordingly. The game continues until the target car reaches the exit.

---

## Tech Stack

- C++
- Object-Oriented Programming (classes and objects)
- 2D arrays for grid representation
- Console input/output

---

## How to Run

1. Compile the program using a C++ compiler: g++ main.cpp -o rushhour
2. Run the executable: ./rushhour

3. Follow the on-screen instructions to play the game.

---

## Project Structure
RushHourGame/
│
├── main.cpp
├── Board.h / Board.cpp
├── Vehicle.h / Vehicle.cpp
└── README.md

## Demo
<img width="917" height="809" alt="Screenshot 2026-04-19 at 1 37 19 PM" src="https://github.com/user-attachments/assets/df578fb1-10ea-4571-8200-6c41932549b5" />

## Author

Created by: Riya Patel



