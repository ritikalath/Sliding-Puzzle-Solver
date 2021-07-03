# Sliding-Puzzle-Solver
### Implementation of A-Star, IDA-Star and BFS Algorithms to solve N*N sliding puzzle.


<p align="center">
  <img width="460" height="460" src="https://miro.medium.com/max/1213/1*YxeZJzfhW4kn5O5wAGbkIg.gif">
</p>
<br />

### game_state.h <br />
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

### IDA_star.cpp <br/>
This is the recursive function which taken a N*N grid as input and solves the puzzle using **IDA-Star** algorithm.
<hr/>

#### Example of input: <br />
The size of grid(N): 3 <br />
The shape of 3*3 grid: <br />
1 8 7 <br />
3 0 5 <br />
4 6 2 <br />

#### Output: <br />
[1  0  7]<br />
[3  8  5]<br />
[4  6  2]<br />
<br/>
[1  7  0]<br />
[3  8  5]<br />
[4  6  2]<br />
<br/>
[1  7  5]<br />
[3  8  0]<br />
[4  6  2]<br />

[1 7 5]<br />
[3 8 2]<br />
[4 6 0]<br />

[1 7 5]<br />
[3 8 2]<br />
[4 0 6]<br />

[1 7 5]<br />
[3 0 2]<br />
[4 8 6]<br />

[1 0 5]<br />
[3 7 2]<br />
[4 8 6]<br />

[1 5 0]<br />
[3 7 2]<br />
[4 8 6]<br />

[1 5 2]<br />
[3 7 0]<br />
[4 8 6]<br />

[1 5 2]<br />
[3 7 6]<br />
[4 8 0]<br />

[1 5 2]<br />
[3 7 6]<br />
[4 0 8]<br />

[1 5 2]<br />
[3 0 6]<br />
[4 7 8]<br />

[1 5 2]<br />
[0 3 6]<br />
[4 7 8]<br />

[1 5 2]<br />
[4 3 6]<br />
[0 7 8]<br />

[1 5 2]<br />
[4 3 6]<br />
[7 0 8]<br />

[1 5 2]<br />
[4 3 6]<br />
[7 8 0]<br />

[1 5 2]<br />
[4 3 0]<br />
[7 8 6]<br />

[1 5 2]<br />
[4 0 3]<br />
[7 8 6]<br />

[1 0 2]<br />
[4 5 3]<br />
[7 8 6]<br />

[1 2 0]<br />
[4 5 3]<br />
[7 8 6]<br />

[1 2 3]<br />
[4 5 0]<br />
[7 8 6]<br />

[1 2 3]<br />
[4 5 6]<br />
[7 8 0]<br />

Summary: IDA-Star,A-Star and BFS,all took 22 steps to solve the given puzzle but IDA-Star took around 0.092 seconds,A-Star took around 0.137 seconds where as BFS took around 5.127 seconds to solve this grid.
