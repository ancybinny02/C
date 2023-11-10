#include <stdio.h>

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void insertRating(int rows, int cols, int matrix[rows][cols], int movieId, int userId, int rating) {
    matrix[movieId][userId] = rating;
}

void deleteRating(int rows, int cols, int matrix[rows][cols], int movieId, int userId) {
    matrix[movieId][userId] = 0;
}

void linearSearch(int rows, int cols, int matrix[rows][cols], int rating) {
    printf("Movies with rating %d:\n", rating);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == rating) {
                printf("Movie %d, User %d\n", i, j);
            }
        }
    }
}

void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    int netflixMatrix[3][3] = {
        {5, 4, 0},
        {0, 0, 3},
        {2, 0, 1}
    };

    printf("Netflix Movies Matrix:\n");
    displayMatrix(rows, cols, netflixMatrix);

    insertRating(rows, cols, netflixMatrix, 1, 2, 4);

    printf("\nNetflix Movies Matrix after insertion:\n");
    displayMatrix(rows, cols, netflixMatrix);

    deleteRating(rows, cols, netflixMatrix, 2, 0);

    printf("\nNetflix Movies Matrix after deletion:\n");
    displayMatrix(rows, cols, netflixMatrix);

    linearSearch(rows, cols, netflixMatrix, 4);

    int matrixA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrixB[2][3] = {{7, 8, 9}, {10, 11, 12}};  
    int resultAddition[2][3];
    int resultMultiplication[2][2];

    addMatrices(2, 3, matrixA, matrixB, resultAddition);  

    printf("\nResult of Matrix Addition:\n");
    displayMatrix(2, 3, resultAddition);

    multiplyMatrices(2, 3, matrixA, 3, 2, matrixB, resultMultiplication);

    printf("\nResult of Matrix Multiplication:\n");
    displayMatrix(2, 2, resultMultiplication);

    return 0;
}
