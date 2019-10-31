import random

WALL = "#"
HALL = " "      

def absolute_coordinate(row, col):
    abs_row = (row*2) + 1
    abs_col = (col*2) + 1
    return (abs_row, abs_col)


def generate_raw_maze(rows, cols):
    n_rows = (rows*2) + 1
    n_cols = (cols*2) + 1

    maze = [[WALL]*n_cols for _ in range(n_rows)]

    for i in range(rows):
        for j in range(cols):
            abs_row, abs_col = absolute_coordinate(i,j)
            maze[abs_row][abs_col] = HALL

    return maze


def init_position():
    return [0,0]

def init_state(rows,cols):
    current_state = [[False]*cols for _ in range(rows)]
    return current_state

def get_successors(row, col, max_rows, max_cols):
    successors = []
    # Get possible successors
    possible_successors = [[row+i,col+j] for i,j in [[0,1],[0,-1],[1,0],[-1,0]]]
    for i,j in possible_successors:
        # Check if inside board
        if i >= 0 and i < max_rows:
            if j >= 0 and j < max_cols:
                successors.append([i,j])

    return successors

def is_goal_state(state):
    is_goal = all([all(x) for x in state])
    return is_goal

def remove_wall(maze, row1, col1, row2, col2):
    abs_coord1 = absolute_coordinate(row1,col1)
    abs_coord2 = absolute_coordinate(row2,col2)

    if abs_coord1[0] == abs_coord2[0]:
        row = abs_coord1[0]
        col = min(abs_coord1[1], abs_coord2[1]) + 1
    elif abs_coord1[1] == abs_coord2[1]:
        row = min(abs_coord1[0], abs_coord2[0]) + 1
        col = abs_coord1[1]

    print(row1, col1)
    print(row2, col2)
    print('~~~~~')
    maze[row][col] = HALL
    return maze

def update_state(state, row, col):
    state[row][col] = True
    return state

def print_maze(maze):
    for line in maze:
        print(''.join(line))

def maze_generator(rows, cols):
    # Define fringe as an empty list (use append and pop to have a LIFO behavior)
    fringe = []
    expanded_coord = []

    current_maze = generate_raw_maze(rows, cols)
    current_coord = init_position()    
    current_state = init_state(rows,cols)

    while True:
        if not current_coord in expanded_coord:
            expanded_coord.append(current_coord)
            # Update state
            current_state = update_state(current_state, current_coord[0], current_coord[1])

            successors = get_successors(current_coord[0], current_coord[1], rows, cols)
            random.shuffle(successors)
            for s in successors:                                
                if not s in expanded_coord:
                    fringe.append(s)

        new_coord = fringe.pop()
        if new_coord != current_coord:
            current_maze = remove_wall(current_maze, current_coord[0], current_coord[1], new_coord[0], new_coord[1])
        current_coord = new_coord

        if is_goal_state(current_state):
            return current_maze

if __name__ == "__main__":
    maze = maze_generator(3,3)
    print_maze(maze)