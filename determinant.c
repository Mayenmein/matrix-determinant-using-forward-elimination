#include<stdio.h>
#include<math.h>

// Function to input system from the user
void inputSystem(int n, float a[n][n])
{
    printf("\nInput the elements of the matrix: \nInput the elements of each row separated by a comma and press the 'enter' key to move to the next row\n"); // Ask for the matrix of coefficients
    //Loop to input the matrix of coefficients from the user
    for(int row=0;row<n;row++) // Loop through the rows of the matrix.
    {
        int column = 0;
        do
        {
            scanf("%f",&a[row][column++]);
        }while(getchar() != '\n' && column < n);
    }
}


// A function to display an n*n matrix.
void printMatrix(int n, float a[n][n])
{
    for(int i=0;i<n;i++) // Loop through the rows of a matrix.
    {
        printf("|");
        for(int j=0;j<n;j++) // For each row, loop through the corresponding columns.
        {
            printf("%9.6f  ",a[i][j]); // Display the ij element of the matrix.
        }
        printf("|\n"); // Print next line.
    }
}
// Function to calculate the determinant of a matrix using Gaussian elimination and the fact that the
// Determinant of an upper-triangular matrix is the the product of it's diagonal elements.
int determinant(int n, float a[n][n])
{
    float m,det = 1; // Define variables for the multiplier m and determinant det.
    int index;
    float max,hold = 0;
    for(int i=0;i<n-1;i++) // Loop to create upper triangular matrix.
    {
        max = abs(a[i][i]); // Set the maximum element to the current diagonal entry, which will be used as a pivot.
        index = i; // Set the index to that of the current diagonal entry.
        for(int j=i+1;j<n;j++) // Loop to search for an entry below the current pivot and set it as the new pivot.
        {
            if(abs(a[j][i])>max)
            {
                max = abs(a[j][i]); // If an entry below the current diagonal is greater than it,set the entry to the max.
                index = j; // Set the index to that of the new max entry.
            }
        }
        if(index > i) // Check if the max index is greater than that of the current index.
        {
            for(int k=i;k<n;k++) // Loop to interchange rows.
            {
                hold = a[i][k]; // Store the value of the current row index to a temporal variable column-wise.
                a[i][k] = a[index][k]; // Store the value of the new max index to the current index column-wise.
                a[index][k] = hold; // Store the value of the current index to that of the new max index.
            }
        }
        for(int j=i+1;j<n;j++)
        {
            m = a[j][i] / a[i][i]; // Set the multiplier.
            for(int k=i+1;k<n;k++) // Loop to eliminate entries below the main diagonal.
            {
                a[j][k] = a[j][k] - (m*a[i][k]);
            }
        }
    }

    for(int i=0;i<n;i++) // Loop to find the determinant of the upper triangular matrix.
    {
        det *= a[i][i]; // Calculate the determinant by multiplying the diagonal entries.
    }
    if(hold != 0) // Checks if pivoting has been carried out and change the sing of the determinant since pivoting changes the sign.
        det *= -1;
    return round(det); // return the calculated determinant.
}

int main()
{
    int n,det;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d",&n);
    float a[n][n];
    inputSystem(n,a);
    printMatrix(n,a);
    det = determinant(n,a);
    printf("The determinant of the matrix is %d\n",det);
}
