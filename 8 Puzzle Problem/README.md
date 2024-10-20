# A* 8-Puzzle Solver

This repository contains a Python implementation of the **A\*** search algorithm to solve the 8-puzzle problem. The 8-puzzle is a sliding puzzle that consists of a 3x3 grid of numbered tiles, with one blank space. The objective is to arrange the tiles in a specified goal configuration by sliding them one at a time.

## How It Works

The code uses **A\*** search, which combines both **cost to reach the current state** (`g(n)`) and the **Manhattan distance heuristic** (`h(n)`), to efficiently find the shortest solution path from the start state to the goal state.

The **Manhattan distance** calculates the sum of the vertical and horizontal distances each tile is from its correct position in the goal configuration.

### Features:
- **Class-Based Design**: The puzzle is modeled using a `Board` class, with methods for generating neighboring states, calculating the Manhattan distance, and performing the A\* search.
- **Recursive Solution Path**: Once the goal state is reached, the solution path is traced recursively back to the start state.
- **Min-Heap for Efficiency**: The priority queue (min-heap) efficiently selects the board state with the lowest estimated cost using Python's `heapq`.
- **Custom Comparisons**: The `__lt__` (less than) operator is overloaded in the `Board` class to compare board states based on their total cost (`f(n)`).

## Cost Function:

\[
f(n) = g(n) + h(n)
\]

Where:
- `g(n)` is the number of moves taken to reach the current state (from the start state).
- `h(n)` is the Manhattan distance of the current state (the sum of the absolute differences between the current and goal positions of each tile).

### Example:

Let’s say you have a puzzle configuration with `g(n) = 5` moves made so far, and the Manhattan distance heuristic `h(n) = 8`.

The total cost function would be:

\[
f(n) = 5 + 8 = 13
\]

This means that the A\* algorithm estimates that it will take a total of 13 moves to reach the goal, including both the moves already made and the estimated remaining moves.

By always selecting the state with the lowest `f(n)`, the A\* algorithm finds the optimal path to the solution efficiently.

