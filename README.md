# Sliding-Puzzle-Solver
Implementation of A-Star, IDA-Star and BFS Algorithms to solve N*N sliding puzzle.
<hr />

### game_state.h:<br />
This header file describes any game state in the search space.It contains structure to store the current state, functions to calculate heuristic (both Manhattan and misplaced tiles) and function to print the steps involved in solving the given instance of sliding puzzle.
<hr />

### solvability.h <br />
This header file contains the function which checks whether the given input instance of sliding puzzle is solvable or not.
<hr />

### solver.h <br/>
This header file contains two functions, **A_star** and **BFS** which takes the initial state of puzzle as input and solves the given instance to get the desired output state.
<hr />

### sliding_puzzle.cpp <br />
This is the main function which takes the following inputs:<br />
    * The size of grid(N
    * The shape of grid (initial state of puzzle)
