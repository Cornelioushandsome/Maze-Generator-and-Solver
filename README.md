# Maze Generator and Solver Manager

## Overview
- This program offers a variety of generation algorithms:
  - Prim's Algorithm
  - Kruskal's Algorithm
  - Recursive-Backtracking Algorithm
    
- As well as many pathfinding algorithms:
  - A* Pathfinding Algorithm
  - Dijkstra's Algorithm
  - Breadth-First-Search
  - Depth-First-Search (recursive)

- This program features unicode characters:
  //insert screenshot here
***
## List of Commands

- ## Built-in Commands
  - **Initalize** - Initialize a maze with integer width and height dimensions | Takes two integer arguments | 5 <= WIDTH = HEIGHT <= 51 | Both height and weight must be odd numbers; if not, they will automatically be incremented by one.
    
  ```bash
  >init [INT-HEIGHT] [INT-WIDTH]
  ```
  ```bash
  >i    [INT-HEIGHT] [INT-WIDTH]
  ```
  
  - **Generate** - Generate a maze with walls and passages using any of the available algorithms | Receives one argument | Maze must already be initialized.
  ```bash
  >gen [GENERATION-ALGORITHM]
  ```
  ```bash
  >g   [GENERATION-ALGORITHM]
  ```

  - **Solve** - Solve a maze using any of the available algorithms | receives one argument | Maze must already be generated.
  ```bash
  >solve [SOLVING-ALGORITHM]
  ```
  ```bash
  >s     [SOLVING-ALGORITHM]
  ```

  - **Render** - Print out the maze using unicode characters | Maze must already be generated.
  ```bash
  >render
  ```
  ```bash
  >r
  ```

  - **Help** - Receive help using the program | Prints out all the available commands.
  ```bash
  >help
  ```
  ```bash
  >h
  ```

  - **Quit** - Quit the program.
  ```bash
  >quit
  ```
  ```bash
  >q
  ```
  ***
- ## Generation Commands 
  - **Plain** - Generate a plain maze with no inner-walls. (Capitalization is imporant!)
  ```bash
  >gen Plain
  ```
  ```bash
  >g   P
  ```
  - **Prim's Algorithm** - Generate a maze using Prim's algorithm; usually leads to shorter paths
  ```bash
  >gen prim
  ```
  ```bash
  >gen p
  ```
  - **Kruskal's Algorithm** - Generate a maze using Kruskal's algorithm; usually leads to medium-length paths
  ```bash
  >gen kruskal
  ```
  ```bash
  >gen k
  ```
  - **Recursive-Backtracking** - Generate a maze using recursive-backtracking; usually leads to very long paths
  ```bash
  >gen recursive
  ```
  ```bash
  >gen r
  ```
  ***
- ## Solving Commands
  - **A*** - Solve a maze using A* pathfinding algorithm; calculates current cost and heuristics; always finds shortest path; generally the most efficient
  ```bash
  >solve astar
  ```
  ```bash
  >solve a
  ```
  - **Dijkstra** - Solve a maze using Dijkstra's algorithm; greedy algorithm that calculates using cost and weights; always finds shortest path
  ```bash
  >solve dijkstra
  ```
  ```bash
  >solve d
  ```
  - **Breadth-First-Search** - Solve a maze using breadth-first-search algorithm; expands equally outward to all directions; always finds shortest path
  ```bash
  >solve breadth
  ```
  ```bash
  >solve b
  ```
  - **Depth-First-Search** - Solve a maze using depth-first-search (aka. recursive-backtracking); Recursively explores each path until a dead-end; not guaranteed to find the shortest path
  ```bash
  >solve recursive
  ```
  ```bash
  >solve r
  ```

  
