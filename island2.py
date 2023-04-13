def main():
    matrix = [[1, 0, 0, 1, 0],
              [0, 1, 0, 0, 1],
              [0, 0, 1, 1, 0],
              [1, 0, 0, 0, 1]]
    
    print("Original matrix:")
    printMatrix(matrix)
    
    matrix = removeIsland(matrix)
    
    print("Modified matrix:")
    printMatrix(matrix)
    
def printMatrix(matrix):
    for row in matrix:
        print(row)

main()
