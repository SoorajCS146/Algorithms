import heapq

class Board:
    def __init__(self, state, goal, parent=None, move=0):
        """
        state: tuple[int] - current board configuration (e.g., (1, 2, 3, 4, 0, 5, 6, 7, 8))
        goal: tuple[int] - goal board configuration (e.g., (1, 2, 3, 4, 5, 6, 7, 8, 0))
        parent: Board - parent board from which this board was reached (used for recursion)
        move: int - number of moves taken so far (g(n) in A* algorithm)
        """
        self.state = state  # Current configuration of the board
        self.goal = goal  # Goal configuration of the board
        self.parent = parent  # Reference to parent board (for recursion)
        self.move = move  # Number of moves taken (g(n))

    def manhattan_distance(self):
        """
        Calculates the Manhattan distance heuristic for the current state.
        Returns:
        int - the Manhattan distance (h(n)) of the current state
        """
        distance = 0  # Example: 0
        for i in range(1, 9):  # Tile numbers from 1 to 8 (ignores blank space)
            x1, y1 = divmod(self.state.index(i), 3)  # Current position of tile i (example: (0,1))
            x2, y2 = divmod(self.goal.index(i), 3)   # Goal position of tile i (example: (0,1))
            distance += abs(x1 - x2) + abs(y1 - y2)  # Manhattan distance for each tile
        return distance  # Example: 3

    def is_goal(self):
        """
        Checks if the current board is in the goal state.
        Returns:
        bool - True if current state equals goal state, False otherwise
        """
        return self.state == self.goal  # Example: True or False

    def get_neighbors(self):
        """
        Generates neighboring boards by sliding the blank tile (0).
        Returns:
        list[Board] - list of neighboring Board objects
        """
        neighbors = []  # Example: [Board(...), Board(...)]
        index = self.state.index(0)  # Position of the blank tile (example: 4)
        x, y = divmod(index, 3)  # Blank tile's coordinates (example: (1, 1))
        
        # Possible directions for sliding the blank tile: (dx, dy)
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
        
        for dx, dy in directions:
            new_x, new_y = x + dx, y + dy  # New position of the blank tile
            if 0 <= new_x < 3 and 0 <= new_y < 3:  # Ensure it's within bounds
                new_index = new_x * 3 + new_y  # New index of blank tile (example: 1)
                new_state = list(self.state)  # Copy current state (example: [1, 2, 3, 4, 0, 5, 6, 7, 8])
                new_state[index], new_state[new_index] = new_state[new_index], new_state[index]  # Swap blank tile
                neighbors.append(Board(tuple(new_state), self.goal, self, self.move + 1))  # Create new Board object
        return neighbors

    def __lt__(self, other):
        """
        Overloads the < operator for comparison between two Board objects.
        Comparison is based on f(n) = g(n) + h(n), where g(n) is the number of moves (self.move)
        and h(n) is the Manhattan distance heuristic.
        """
        return (self.move + self.manhattan_distance()) < (other.move + other.manhattan_distance())

    def a_star(self):
        """
        Implements the A* algorithm to solve the 8-puzzle.
        Uses a priority queue (min-heap) with overloaded __lt__ to determine the minimum state.
        Returns:
        list[tuple[int]] - list of board states from start to goal
        """
        frontier = []  # Min-heap, stores (Board objects)
        heapq.heappush(frontier, self)  # Push the initial board onto the heap

        # Dictionary to track the cost of reaching a state
        cost_so_far = {self.state: self.move}  # Example: {(1, 2, 3, 4, 0, 5, 6, 7, 8): 0}

        while frontier:
            # Pop the board with the lowest f(n) from the heap
            current_board = heapq.heappop(frontier)

            # If the goal state is reached, return the solution path
            if current_board.is_goal():
                return current_board.get_solution_path()

            # Explore the neighbors of the current board
            for neighbor in current_board.get_neighbors():
                new_cost = current_board.move + 1  # Cost for the neighbor (example: 1)
                if neighbor.state not in cost_so_far or new_cost < cost_so_far[neighbor.state]:
                    cost_so_far[neighbor.state] = new_cost  # Update the cost for this state
                    heapq.heappush(frontier, neighbor)  # Push neighbor onto the heap

        return None  # Return None if no solution is found

    def get_solution_path(self):
        """
        Recursively traces back from the goal to the start state using the parent references.
        Returns:
        list[tuple[int]] - list of board states from start to goal
        """
        path = []  # Example: [(start state), ..., (goal state)]
        current = self  # Example: Board object representing the goal state
        while current:
            path.append(current.state)  # Add the current state to the path
            current = current.parent  # Move to the parent board (previous state)
        return path[::-1]  # Reverse the path to get the correct order (start to goal)

    def print_board(self):
        """
        Prints the current state of the board.
        """
        for i in range(3):
            print(self.state[i * 3:(i + 1) * 3])  # Example: [1, 2, 3]
        print()
# Start state (1, 2, 3, 4, 0, 5, 6, 7, 8)
start_state = (1, 2, 3, 4, 0, 5, 6, 7, 8)  # Example: start state
# Goal state (1, 2, 3, 4, 5, 6, 7, 8, 0)
goal_state = (1, 2, 3, 4, 5, 6, 7, 8, 0)  # Example: goal state

# Initialize the A* solver
start_board = Board(start_state, goal_state)
solution_path = start_board.a_star()

if solution_path:
    print("Solution found in {} moves:".format(len(solution_path) - 1))
    for state in solution_path:
        board = Board(state, goal_state)
        board.print_board()
else:
    print("No solution found.")

