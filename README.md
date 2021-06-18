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
* The size of grid(N) <br />
* The shape of grid (initial state of puzzle) <br />
and solves the grid setting using A-Star or BFS. <br />
<hr />

#### Example of input: <br />
<hr />
The size of grid(N): 3 <br />
The shape of 3*3 grid: <br />
1 8 7 <br />
3 0 5 <br />
4 6 2 <br />
<hr/>

##### Output: <br />
[1 0 7]
[3 8 5]
[4 6 2]

[1 7 0]
[3 8 5]
[4 6 2]

[1 7 5]
[3 8 0]
[4 6 2]

[1 7 5]
[3 8 2]
[4 6 0]

[1 7 5]
[3 8 2]
[4 0 6]

[1 7 5]
[3 0 2]
[4 8 6]

[1 0 5]
[3 7 2]
[4 8 6]

[1 5 0]
[3 7 2]
[4 8 6]

[1 5 2]
[3 7 0]
[4 8 6]

[1 5 2]
[3 7 6]
[4 8 0]

[1 5 2]
[3 7 6]
[4 0 8]

[1 5 2]
[3 0 6]
[4 7 8]

[1 5 2]
[0 3 6]
[4 7 8]

[1 5 2]
[4 3 6]
[0 7 8]

[1 5 2]
[4 3 6]
[7 0 8]

[1 5 2]
[4 3 6]
[7 8 0]

[1 5 2]
[4 3 0]
[7 8 6]

[1 5 2]
[4 0 3]
[7 8 6]

[1 0 2]
[4 5 3]
[7 8 6]

[1 2 0]
[4 5 3]
[7 8 6]

[1 2 3]
[4 5 0]
[7 8 6]

[1 2 3]
[4 5 6]
[7 8 0]




