#include <stdio.h>
#include <stdlib.h>




//We will frequently use the formula in+j-(i(i+1))/2 to convert a two-dimensional upper triangular matrix into a one-dimensional array.
//With 'i' representing the row number, 'j' representing the column number, and 'n' representing the size of the array, we will frequently use the formula in+j-(i(i+1))/2 to convert a two-dimensional upper triangular matrix into a one-dimensional array.
//The source of this information is "https://www.geeksforgeeks.org/convert-given-upper-triangular-matrix-to-1d-array/"


// Function to multiply two upper triangular matrices and store the result in another upper triangular matrix
void multiplyUpperTriangularMatrices(int *mat1, int *mat2, int *result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Initialize the sum for the current element in the result matrix
            int sum = 0;
            // Calculate the dot product of the corresponding elements in mat1 and mat2
            for (int k = i; k <= j; k++) {
            // Adjust the indices to access the upper triangular elements in mat1 and mat2


                //The formula enabling this assignment has been discovered with the assistance of AI.
                //Its fundamental logic is based on the operations depicted in the attached visual: "https://prnt.sc/D7JhHXNCcKdh."
                sum += mat1[i*n+k-(i*(i+1))/2] * mat2[k*n+j-(k*(k+1))/2];
            }
        // Assign the calculated sum to the corresponding position in the result matrix
        result[i*n+j-(i*(i+1))/2]=sum;
        }
    }
}
// Function to print the elements of a one-dimensional array
void print1DArray(int *matrix, int n) {
    int i;
    // Iterate through the array and print each element
    for (i = 0; i < n; i++) {
        printf("%d ", matrix[i]);
    }
    // Move to the next line after printing all elements
    printf("\n");
}
// Function to print the upper triangular elements of a matrix represented as a one-dimensional array
void printTraditionalMatrix(int *matrix, int n) {
    int i, j;
    // Iterate through rows
    for (i = 0; i < n; i++) {
        // Iterate through columns
        for (j = 0; j < n; j++) {
            // Check if the current element is in the upper triangular part
            if (i > j) {
                printf("0\t");// Print zero for lower triangular elements
            } else {
                // Access the upper triangular element and print it
                printf("%d\t", matrix[(i*(2*n-i+1)/2)+(j-i)]);
            }
        }
        // Move to the next line after printing a row
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("input.txt", "r"); // We obtained the first value from the input.txt file.
    if (file == NULL) {
        fprintf(stderr, "The file was not found.\n");
        return 1;
    }
    // Read the first value from the file, which represents the size of the matrices.
    int n;
    fscanf(file, "%d", &n);

    int *matrixA = (int *)malloc(n * (n + 1) / 2 * sizeof(int)); // We allocated memory for the first matrix.
    if (matrixA == NULL) {  // When testing the program on my own, my program didn't work due to errors that occurred during dynamic memory allocation.
                            // I needed this array to understand where the error originated, although it's not often necessary

    fprintf(stderr, "Memory allocation error.\n");
    return 1;}

    int *matrixB = (int *)malloc(n * (n + 1) / 2 * sizeof(int)); // We allocated memory for the second matrix.
    if (matrixB == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    return 1;}
    int *matrixResult = (int *)malloc(n * (n + 1) / 2 * sizeof(int)); // We allocated memory for the result matrix.
    if (matrixResult == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    return 1;}

     int i, j;
    // Iterate through the rows and columns of the upper triangular matrix
    for (i = 0; i < (n*(n+1))/2; i++) {

            // Read each element from the file and store it in the corresponding position
            //scanf(file, "%d", &matrixA[i * (i + 1) / 2 + j]);
            fscanf(file, "%d", &matrixA[i]);

    }

    // Iterate through the rows and columns of the upper triangular matrix
    for (j = 0; j < (n*(n+1))/2; j++) {

            // Read each element from the file and store it in the corresponding position
            fscanf(file, "%d", &matrixB[j]);

    }
    // Close the file after reading
    fclose(file); // Close the file to release system resources.



    // Multiply two upper triangular matrices: matrixA and matrixB
    multiplyUpperTriangularMatrices(matrixA, matrixB, matrixResult, n);

    // Print the result of multiplication as a one-dimensional array
    printf("Multiplication Result as 1D Array:\n"); // We printed the one dimensional array.
    print1DArray(matrixResult, (n*(n+1))/2);

    // Print the result of multiplication as a traditional matrix
    printf("\nMultiplication Result as Traditional Matrix:\n"); // We printed the Traditional Matrix.
    printTraditionalMatrix(matrixResult, n);


    free(matrixA); // "We freed the memory for all dynamically allocated regions, making those memory areas unusable for the program."
    free(matrixB);
    free(matrixResult);

    return 0;

}
