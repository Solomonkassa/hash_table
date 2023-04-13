def removeIsland(matrix):
    rows, cols = len(matrix), len(matrix[0])
    
    # Helper function to recursively mark connected 1s as 0
    def dfs(i, j):
        if i < 0 or i >= rows or j < 0 or j >= cols or matrix[i][j] != 1:
            return
        matrix[i][j] = 0
        dfs(i+1, j)
        dfs(i-1, j)
        dfs(i, j+1)
        dfs(i, j-1)
    
    # Traverse the matrix and mark connected 1s as 0 except for the isolated 1s on the boundary
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 1:
                if i == 0 or i == rows-1 or j == 0 or j == cols-1:
                    dfs(i, j)
                else:
                    matrix[i][j] = 0
    
    # Return the modified matrix
    return matrix
